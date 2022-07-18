#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<fstream>
using namespace std;
fstream data,indx;
char pri[125][15];
int ind[125],count=0;
int flag_updt=0;
class Index_student
{struct student
{
char regno[11];
char name[20];
char address[30];
char sem[2];
char branch[5];
char college[10];
};
public:
void Insert();
void Delete();
void Display();
void LoadIndex();
void WriteIndex();
};
void Index_student::Insert()
{
char buf[100];
int pos;
student s;
data.open("std.txt",ios::out|ios::app);
data.seekg(0,ios::end);
pos=data.tellg();
cout<<"---------------------------\n";
cout<<"ENTER RECORD DETAILS\n";
cout<<"---------------------------\n";
cout<<"RegNo : ";
cin>>s.regno;
for(int i=0;i<count;i++)
{
if(strcmp(pri[i],s.regno) == 0) {
cout<<endl;
cout<<"DUPLICATE RECORD !!!";
data.close();
return;
}
}
cout<<"Name : ";
cin>>s.name;
cout<<"Address : ";
cin>>s.address;
cout<<"Sem : ";
cin>>s.sem;
cout<<"Branch : ";
cin>>s.branch;
cout<<"College : ";
cin>>s.college;
sprintf(buf,"|%s|%s|%s|%s|%s|%s #",s.regno,s.name,s.address,s.sem,s.branch,s.college);
data<<buf;
strcpy(pri[count],s.regno);
ind[count]=pos;
count++;
flag_updt=1;
data.close();
}
void Index_student::Delete()
{
char reg[20],buf[100],usn[15];
int pos;
int flag=0;
cout<<"ENTER URN:";
cin>>reg; data.open("std.txt",ios::in|ios::out);
for(int i=0;i<count;i++)
if(strcmp(pri[i],reg) == 0)
{
flag=1;
data.seekg(ind[i],ios::beg);
data.getline(buf,100,'#');
buf[0]='*';
pri[i][0]='*';
data.seekg(ind[i],ios::beg);
data<<buf;
cout<<"RECORD DELETED\n\n";
flag_updt=1;
break;
}
if(flag==0)
{
cout<<"RECORD NOT FOUND !!!\n\n";
}
data.close();
}
void Index_student::Display()
{
int flag=0;
char buf[100];
char regno[20];
student s;
cout<<"ENTER URN: ";
cin>>regno;
data.open("std.txt",ios::in|ios::out);
for(int i=0;i<count;i++)
{ if(strcmp(pri[i],regno) == 0)
{
flag=1;
data.seekg(ind[i]);
data.getline(buf,100,'#');
sscanf(buf,"|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|% [^|]#",s.regno,s.name,s.address,s.sem,s.branch,s.college);
cout<<"--------------------------";
cout<<endl<<"RECORD DETAILS";
cout<<endl<<"--------------------------";
cout<<endl<<"URN : "<<s.regno;
cout<<endl<<"NAME : "<<s.name;
cout<<endl<<"ADDRESS : "<<s.address;
cout<<endl<<"SEMESTER : "<<s.sem;
cout<<endl<<"BRANCH : "<<s.branch;
cout<<endl<<"COLLEGE : "<<s.college;
cout<<"\n";
}
}
if(flag==0)
cout<<"RECORD DOES NOT EXISTS\n\n";
data.close();
}
void Index_student::LoadIndex()
{
char buf[100],temp[100];
indx.open("indx.txt",ios::in);
while(indx)
{
indx.getline(buf,100,'#');
if(indx.eof())
break;
sscanf(buf,"|%[^|]|%[^|]",pri[count],temp);ind[count]=atoi(temp);
count++;
}
indx.close();
}
void Index_student::WriteIndex()
{
char buf[100];
indx.open("indx.txt",ios::out);
for(int i=0;i<count;i++)
{
sprintf(buf,"%d",ind[i]);
indx<<"|"<<pri[i]<<"|"<<buf<<"|"<<"#";
}
indx.close();
}
main()
{
Index_student I;
I.LoadIndex();
int ch;
while(1)
{
cout<<"1->INSERT RECORD\n";
cout<<"2->DELETE RECORD\n";
cout<<"3->DISPLAY INDIVIDUAL RECORD\n";
cout<<"4->QUIT\n";
cout<<"ENTER YOUR CHOICE:";
cin>>ch;
switch(ch)
{ case 1:I.Insert();
break;
case 2:I.Delete();
break;
case 3:I.Display();
break;
case 4:if(flag_updt==1)
I.WriteIndex();
exit(0);
}
}
}

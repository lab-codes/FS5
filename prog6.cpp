#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<fstream>
using namespace std;
fstream data,pri_ind,sec_ind;
char pri[125][15],sec[125][40],usn[125][20];
int ind[125],count;
class Sec_Index_student
{
struct student
{
char regno[11],name[20],address[30],sem[2],branch[5],college[10];
};public:
void Insert();
void Delete();
void Display();
void LoadIndex();
void WriteIndex();
};
void Sec_Index_student::Insert()
{
char buf[100];
int pos,mid;
student s;
data.open("stu.txt",ios::out|ios::app);
data.seekg(0,ios::end);
pos=data.tellg();
cout<<"ENTER RECORD DETAILS\n";
cout<<"RegNo : ";
cin>>s.regno;
for(int i=0;i<count;i++)
{
if(strcmp(s.regno,pri[i])==0)
{
cout<<"DUPLICATE RECORD!!!";
data.close();
return;
}
}
cout<<"Name:";
cin>>s.name;
cout<<"Address:";
cin>>s.address;
cout<<"Sem:"; cin>>s.sem;
cout<<"Branch:";
cin>>s.branch;
cout<<"College:";
cin>>s.college;
sprintf(buf,"|%s|%s|%s|%s|%s|%s|#",s.regno,s.name,s.address,s.sem,s.branch,s.college);
data<<buf;
strcpy(pri[count],s.regno);//pri record
ind[count]=pos;
strcpy(sec[count],s.name);//sec record
strcpy(usn[count],s.regno);
count++;
this->WriteIndex();
data.close();
}
void Sec_Index_student::Delete()
{
char buf[100],name[20];
int flag=0,indx=count;
cout<<"enter the name";
cin>>name;
cout<<count<<endl;
data.open("stu.txt",ios::in|ios::out);
for(int i=0;i<count;i++)
 {
 if(strcmp(sec[i],name)==0)
{
indx=i;
 break;
}
}
if(indx<count) {for(int i=0;i<count;i++)
{
if(strcmp(usn[indx],pri[i])==0)
{
flag=1;
data.seekg(ind[i],ios::beg);
data.getline(buf,100,'#');
buf[0]='*';//delete stu rec
sec[indx][0]='*';
pri[i][0]='*';//delete pri index
data.seekg(ind[i],ios::beg);
data<<buf;//write deleted record
cout<<endl<<"RECORD DELETED\n";
this->WriteIndex();
data.close();
 return;
}
}
}
if(flag==0)
{
cout<<"\n RECORD NOT FOUND"<<endl;
}
data.close();
}
void Sec_Index_student::Display()
{
char buf[100],name[20];
int flag=0,indx=count;
student s; cout<<"enter the name";
cin>>name;
data.open("stu.txt",ios::in|ios::out);
for(int i=0;i<count;i++) { if(strcmp(sec[i],name)==0) { indx=i; break; } }
for(int i=0;i<count;i++)
 {
 if(strcmp(usn[indx],pri[i])==0)
{
flag=1;
data.seekg(ind[i],ios::beg);
data.getline(buf,100,'#');
sscanf(buf,"|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]#",s.regno,s.name,s.address,s.sem,s.branch,s.college);
cout<<"\nRECORD DETAILS"<<endl;
cout<<endl<<"URN : "<<s.regno;
cout<<endl<<"NAME : "<<s.name;
cout<<endl<<"ADDRESS : "<<s.address;
cout<<endl<<"SEMESTER : "<<s.sem;
cout<<endl<<"BRANCH : "<<s.branch<<endl;
data.close();
return;
 }
}
if(flag==0)
cout<<"RECORD DOES NOT EXIST\n";
data.close();
}
void Sec_Index_student::LoadIndex()
{
char buf[100],temp[100];count=0;
pri_ind.open("pri_index.txt", ios::in);
sec_ind.open("sec_index.txt",ios::in);
while(pri_ind)
{
pri_ind.getline(buf,100,'#');
if(pri_ind.eof())
break;
sscanf(buf,"|%[^|]|%[^|]",pri[count],temp);
ind[count]=atoi(temp);
count++;
}
count=0;
while(sec_ind)
{
sec_ind.getline(buf,100,'#');
if(sec_ind.eof())
break;
sscanf(buf,"|%[^|]|%[^|]",sec[count],usn[count]);
count++;
}
pri_ind.close();
sec_ind.close();
}
void Sec_Index_student::WriteIndex()
{
char buf[100];
pri_ind.open("pri_index.txt", ios::out);
sec_ind.open("sec_index.txt",ios::out);
//bubble_sort();
for(int i=0;i<count;i++)
{pri_ind<<"|"<<pri[i]<<"|"<<ind[i]<<"|"<<"#";//pri record writing
}
for(int i=0;i<count;i++)
{
sec_ind<<"|"<<sec[i]<<"|"<<usn[i]<<"|"<<"#";//sec record writing
}
pri_ind.close();
sec_ind.close();
}
main()
{
Sec_Index_student I;
char name[20],regno[20];
I.LoadIndex();
int ch;
while(true)
{
int c;
cout<<" 1->INSERT RECORD\n";
cout<<" 2->DELETE RECORD\n";
cout<<" 3->DISPLAY INDIVIDUAL RECORD\n";
cout<<" 4->exit\n";
cout<<"ENTER YOUR CHOICE :";
cin>>c;
switch(c)
{
case 1:I.Insert();
 break;
case 2:I.Delete();
 break;
case 3:I.Display();
 break; default: exit(0);
}
}
}

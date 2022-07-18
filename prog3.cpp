#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#define RECORDSIZE 50
using namespace std;
fstream file;
class varlen_student
{
struct student
{
char usn[11],name[15],branch[5],college[15];
};
public:
void pack();
void unpack();void search();
void modify();
};
void varlen_student::pack()
{
student s;
char buff[RECORDSIZE+1];
cout<<"enter usn,name,branch and college\n";
cin>>s.usn>>s.name>>s.branch>>s.college;
sprintf(buff,"%s|%s|%s|%s|$",s.usn,s.name,s.branch,s.college);
file.open("pg.txt",ios::out|ios::app);
file<<buff;
file.close();
}
void varlen_student::unpack()
{
student s;
char buff[RECORDSIZE+1];
file.open("pg.txt",ios::in);
while(!file.eof())
{
file.getline(buff,RECORDSIZE,'$');
if(file.eof())
break;
sscanf(buff,"%[^|]|%[^|]| %[^|]|%[^|]|$", s.usn,s.name,s.branch,s.college);
cout<<"\n----------------\nusn\t:"<<s.usn<<"\nname\t:"<<s.name<<"\nbranch\t:"
<<s.branch<<"\ncollege:"<<s.college<<endl;
}
file.close();
}
void varlen_student::search(){
student s;
int found=0;
char buff[RECORDSIZE+1];
char usn[11];
file.open("pg.txt",ios::in);
cout<<"\nEnter the usn to be searched:";
cin>>usn;
while(!file.eof() && found==0)
{
file.getline(buff,RECORDSIZE,'$');
if(file.eof())
break;
sscanf(buff,"%[^|]|%[^|]|%[^|]|%[^|]|$",s.usn,s.name,s.branch,s.college);
if(strcmp(s.usn,usn)==0)
{
found=1;
cout<<"\nRecord found";
cout<<"\n----------------
\nusn\t:"<<s.usn<<"\nname\t:"<<s.name<<"\nbranch\t:"<<s.branch<<"\ncollege:"<<s.college<<endl;
break;
}
}
if(found==0)
cout<<"\nRecord not found\n";
file.close();
}
void varlen_student::modify()
{
int n=0,found=0;
student s;char usn[11];
char buff[RECORDSIZE+1];
fstream newfile;
file.open("pg.txt",ios::in);
newfile.open("temp.txt",ios::out|ios::app);
cout<<"\nEnter the usn to be modified:";
cin>>usn;
while(!file.eof())
{
file.getline(buff,RECORDSIZE,'$');
if(file.eof())
break;
sscanf(buff,"%[^|]|%[^|]|%[^|]|%[^|]|$",s.usn,s.name,s.branch,s.college);
if(strcmp(s.usn,usn)==0)
{
found=1;
cout<<"\nRe-Enter student details: ";
cout<<"enter usn,name,branch and college\n";
cin>>s.usn>>s.name>>s.branch>>s.college;
}
sprintf(buff,"%s|%s|%s|%s|$",s.usn,s.name,s.branch,s.college);
newfile<<buff;
}
if(!found)
cout<<"\n\nRecord to be modified does not exist in file\n";
file.close();
newfile.close();
remove("pg.txt");
rename("temp.txt","pg.txt");
}int main()
{
int ch;
varlen_student b;
for(;;)
{
cout<<"\n1.pack\t2.unpack\t3.search\t4.modify\t5.exit\nEnter your choice:";
cin>>ch;
switch(ch)
{
case 1: b.pack();
break;
case 2: b.unpack();
break;
case 3: b.search();
break;
case 4: b.modify();
break;
default:exit(0);
}
}
}

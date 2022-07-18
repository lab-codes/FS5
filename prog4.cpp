#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
fstream file;
class varlen_student
{
struct student
{
char usn[11],name[15],sem[2],dept[5];
};
public: void pack();
void unpack();
void search();
};
void varlen_student::pack()
{
int count=0;
char b[100],c[150],temp[100];
student s;
cout<<"enter usn, name, sem, dept";
cin>>s.usn>>s.name>>s.sem>>s.dept;
file.open("stu.txt",ios::in|ios::app);
while(!file.eof())
{ file.getline(temp,100,'#');
if(file.eof())
break;
count++;
}
 file.close();
file.open("stu.txt",ios::out|ios::app);
sprintf(b,"%s|%s|%s|%s|#",s.usn,s.name,s.sem,s.dept);
sprintf(c,"|%d|%d$",count,strlen(b));
strcat(c,b);
file<<c;
file.close();
}
void varlen_student::unpack()
{
char b[100];
student s;
file.open("stu.txt",ios::in);
while(!file.eof())
{
file.getline(b,100,'$');
file.getline(b,100,'#');
if(file.eof())
break;
sscanf(b,"%[^|]|%[^|]|%[^|]|%[^|]|#",s.usn,s.name,s.sem,s.dept);
cout<<s.usn<<" "<<s.name<<" "<<s.sem<<" "<<s.dept<<endl;
}
file.close();
}
void varlen_student::search()
{
char b[100],rrn[11],temp[100],len[10]; int flag=0;
student s;
file.open("stu.txt",ios::in);
cout<<"\n enter a rrn to be searched\n";
cin>>rrn;
while(!file.eof())
{
file.getline(b,100,'#');
if(file.eof())
break;
sscanf(b,"|%[^|]",temp);
if(strcmp(temp,rrn)==0)
{
flag=1;
//|100|13$1|diya|3|is|#
sscanf(b,"|%[^|]|%[^$]$%[^|]|%[^|]|%[^|]|%[^|]|#",temp,len,s.usn,s.name,s.sem,s.dept);
cout<<s.usn<<" "<<s.name<<" "<<s.sem<<" "<<s.dept<<"\n";
break;
}
}
if(flag==0)
cout<<"\n key not found\n";
file.close();
}
main()
{
varlen_student b;
int ch;
for(;;)
{
cout<<"\n1:pack\t2:unpack\t3:search\t4:exit\nenter your choice:";cin>>ch;
switch(ch)
{
case 1: b.pack();
break;
case 2: b.unpack();
break;
case 3: b.search();
break;
default: exit(0);
}
}
}

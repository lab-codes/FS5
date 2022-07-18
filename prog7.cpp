#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;
fstream list0, list1, list2;
class intersect
{
public:
void sort(char [25][30],int);
void input(char [25][30],int);
};
void intersect::sort(char s[25][30],int count)
{int i,j;
char temp[40];
for(i=1;i<count;i++)
for(j=0;j<count-i;j++)
if(strcmp(s[j],s[j+1])>0)
{
strcpy(temp,s[j]);
strcpy(s[j],s[j+1]);
strcpy(s[j+1],temp);
}
}
void intersect::input(char str[25][30],int lnum)
{
int i,j;
if(lnum==0)
list0.open("list0.txt",ios::out);
else
list1.open("list1.txt",ios::out);
for(i=0;;i++)
{
cin>>str[i];
if(strcmp(str[i],"#")==0)
break;
}
sort(str,i);
if(lnum==0)
{
for(j=0;j<i;j++)
{
list0<<str[j]<<"\n";
}
}else
{
for(j=0;j<i;j++)
{
list1<<str[j]<<"\n";
}
}
list0.close();
list1.close();
}
main()
{
char str0[25][30],str1[25][30];
char buf1[30],buf2[30];
intersect I;
cout<<"Enter the names of list1(To terminate enter string #)\n";
I.input(str0,0);
cout<<"Enter the names of list2(To terminate enter string #)\n";
I.input(str1,1);
list0.open("list0.txt",ios::in);
list1.open("list1.txt",ios::in);
list2.open("list2.txt",ios::out);
list0.getline(buf1,50,'\n');
list1.getline(buf2,50,'\n');
while(!list0.eof() && !list1.eof())
{
if(strcmp(buf1,buf2)==0)
{
list2<<buf1<<endl;
list0.getline(buf1,50,'\n');
list1.getline(buf2,50,'\n');}
else if(strcmp(buf1,buf2)<0)
list0.getline(buf1,50,'\n');
else
list1.getline(buf2,50,'\n');
}
if(strcmp(buf1,buf2)==0)
cout<<buf1<<endl;
list0.close();
list1.close();
list2.close();
list2.open("list2.txt",ios::in);
list2.getline(buf1,50,'\n');
if(strcmp(buf1,"\0")==0)
cout<<" No matching strings found:"<<endl;
else
{
cout<<"Names in both the lists are"<<endl;
while(1)
{
cout<<buf1<<endl;
list2.getline(buf1,50,'\n');
if(list2.eof()) break;
}
}
}

#include<stdio.h>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;
int main()
{
char name[20][20],usn[20][20], temp[10], temp1[20];
fstream list[8];
fstream file;
int flag=0, n,i,j;
char ip_fname[8][8]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt"};
cout<<"Enter the no of records: ";
cin>>n;
for(i=0;i<8;i++)list[i].open(ip_fname[i],ios::out);
for(i=0;i<n;i++)
{
cout<<"Name:";
cin>>name[i];
cout<<"Usn:";
cin>>usn[i];
list[i%8]<<name[i]<<"|"<<usn[i]<<"\n";
}
for(i=0;i<8;i++)
list[i].close();
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(strcmp(name[i],name[j])>0)
{
strcpy(temp,name[i]);
strcpy(name[i],name[j]);
strcpy(name[j], temp);
strcpy(temp1,usn[i]);
strcpy(usn[i],usn[j]);
strcpy(usn[j], temp1);
}
}
}
file.open("merge.txt",ios::out);
cout<<"sorted name:";
for(i=0;i<n;i++)
{
if(strcmp(name[i],name[i-1])==0) continue;file<<name[i]<<"|"<<usn[i]<<"\n";
cout<<name[i]<<"|"<<usn[i]<<"\n";
flag=1;
}
if(flag=1)
cout<<"completed";
else
cout<<"not completed";
}

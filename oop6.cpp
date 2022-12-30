 #include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class student
{
public:
char name[10];
char DOB[10];
long int telephone;
int rollno;

bool operator==(const student&i1)
{
if(rollno==i1.rollno)
return 1;
return 0;
}

bool operator<(const student&i1)
{
if(rollno<i1.rollno)
return 1;
return 0;
}
};

vector<student>o1;
void print(student&i1);
void display();
void insert();
void search();

bool compare(const student&i1,const student&i2)
{
return i1.rollno<i2.rollno;
}
int main()
{
int ch;
do
{
cout<<"\n***Menu*";
cout<<"\n1.Insert";
cout<<"\n2.Display";
cout<<"\n3.Search";
cout<<"\n4.Sort";
cout<<"\n6.Exit";
cout<<"\nEnter your choice";
cin>>ch;
switch(ch)
{
case 1:
insert(); 
break;
case 2:
display();
break;
case 3:
search();
break;
case 4:
sort(o1.begin(),o1.end(),compare);
cout<<"\n\nSorted on Roll numbers";
display();
break;
case 5:
exit(0);
}
}
while(ch<=5);
return 0;
}
void insert()
{
student i1;
cout<<"\nEnter Student Name:";;
cin>>i1.name;
cout<<"\nEnter Student DOB:";;
cin>>i1.DOB;
cout<<"\nEnter Student Telephone:";;
cin>>i1.telephone;
cout<<"\nEnter Student Roll number:";;
cin>>i1.rollno;
o1.push_back(i1);
}
void display()
{
for_each(o1.begin(),o1.end(),print);
}
void print(student&i1)
{
cout<<"\n";
cout<<"\nStudent Name:"<<i1.name;
cout<<"\nStudent DOB:"<<i1.DOB;
cout<<"\nStudent Telephone:"<<i1.telephone;
cout<<"\nStudent Roll number:"<<i1.rollno;
}
void search()
{
vector<student>::iterator p;
student i1;
cout<<"\n Enter Student Roll number to search:";
cin>>i1.rollno;;
p=find(o1.begin(),o1.end(),i1);
if(p==o1.end())
{
cout<<"\nNot Found,";
}
else
{
cout<<"\nFound";
}
}

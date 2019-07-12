#include<iostream>
#include<string>
using namespace std;
class Person
{
protected:
    int no;
    string name;
    string sex;
    int age;
public:
    Person(int no1,string name1,string sex1,int age1)
    {
        no=no1;
        name=name1;
        sex=sex1;
        age=age1;
     }
    void print()
    {
        cout << "no is "<<no<<endl;
        cout << "name is "<<name<<endl;
        cout << "sex is "<<sex<<endl;
        cout << "age is "<<age<<endl;
     }
};
class Student: public Person
{
public:
    Student(int no1,string name1,string sex1,int age1,string zy1,int grade1):Person(no1,name1,sex1,age1)
    {
    zy=zy1;
    grade=grade1;
    }
    void print1()
    {
        Person::print();
        cout<<"zy is "<<zy<<endl;
        cout<<"grade is "<<grade<< endl;
     }
protected:
    string zy;
    int grade;
};
int main()
{
    Student a(01,"小明","男",18,"网络工程",95);
    a.print1();
    return 0;
 
}


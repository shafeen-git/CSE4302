#include <iostream>
#include <string>
using namespace std;
class Person{
private:
    string name;
    int age;
    int personID;
    static int ID;
public:
    Person():name("John Doe"),age(0),personID(++ID){}
    Person(const string& Name, int Age):name(Name),age(Age),personID(++ID){}
    ~Person(){
        cout <<"~Person() is called"<<"\n";
    }
    void displayDetails()const{
        cout <<name<< ","<<" Age: "<<age<< ","<<" P_ID: "<<personID<<"\n";
    }
    const string& getName()const{
        return name;
    }
    int getAge()const{
        return age;
    }
    int getPersonID()const{
        return personID;
    }
    void setName(const string& Name){
        this->name=Name;
    }
    void setAge(int Age){
        this->age=Age;
    }
    bool operator==(const Person& other)const{
        if(name == other.name && age == other.age){
            return true;
        }
        else return false;
    }
    friend ostream operator<<(ostream& os,const Person& p){
        p.displayDetails();
        return os;
    }
};
int Person::ID=0;
class Student:public Person{
private:
    int sid;
public:
    Student():Person(),sid(0){}
    Student(const string& Name,int Age,int Sid):Person(Name, Age),sid(Sid){}
    int getSID()const{
        return sid;
    }
    void setSID(int Sid){
        this->sid=Sid;
    }
};
class Faculty : public Person{
private:
    string designation;
public:
    Faculty():Person("Mr. X",22),designation("Lecturer"){}
    Faculty(const string& Name, int Age, const string& Designation): Person(Name, Age), designation(Designation){}
    ~Faculty(){
        cout << "~Faculty() is called" << "\n";
    }
    const string& getDesignation()const{
        return designation;
    }
    void setDesignation(const string& Designation){
        this->designation = Designation;
    }
};
class Visitor:private Person{
private:
    string visitingPurpose;
public:
    Visitor():Person(),visitingPurpose("For sickness"){}
    Visitor(const string& Name,int Age,const string& Purpose):Person(Name,Age),visitingPurpose(Purpose){}
    const string& getVisitingPurpose()const{
        return visitingPurpose;
    }
    void setVisitingPurpose(const string& Purpose){
        visitingPurpose=Purpose;
    }
    void displayVisitor()const{
        displayDetails();
        cout << "Purpose: " << visitingPurpose <<"\n";
    }
};
void TestPerson(){
    Person p1, p2("Faisal",30);
    if(p1.getName()=="John Doe" && p1.getAge() == 0 &&p1.getPersonID()==1) cout<< "Zero Arg Constructor - Passed"<<endl;
    else  cout<< "Zero Arg Constructor - Failed!!!!"<<endl;

    if(p2.getName()=="Faisal" && p2.getAge() == 30 &&p2.getPersonID()==2) cout<< "Argumented Constructor - Passed"<<endl;
    else  cout<< "Argumented Constructor - Failed!!!!"<<endl;

    if(p1==p1) cout<< " operator == - Passed"<<endl;
    else cout<< " operator == - Failed!!!!"<<endl;

}

void TestStudent(){
    Student s1;
}
void TestFaculty(){
    Faculty f;
    if(f.getName()=="Mr. X"&&f.getAge()==22&&f.getDesignation()=="Lecturer") cout<< "Zero Arg Constructor Faculty - Passed"<<endl;
    else cout<< "Zero Arg Constructor Faculty - Failed!!!!"<<endl;
}
void TestVisitor()
{
    Visitor v;
}

int main()
{
    TestPerson();
    TestStudent();
    TestFaculty();
    TestVisitor();
}


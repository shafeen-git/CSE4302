#include <iostream>
#include <string>
using namespace std;

class Student : public Person {
private:
    int sid;

public:
    Student() : Person(), sid(0) {}
    Student(const string& name, int age, int sid)
        : Person(name, age), sid(sid) {}
    void setSID(int sid) {
        this->sid = sid;
    }
    int getSID() const {
        return sid;
    }


    void displayDetails() const {
        Person::displayDetails();
        cout << "SID: " << sid << endl;
    }
};


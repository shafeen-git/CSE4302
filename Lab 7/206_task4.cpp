#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    string name;
    int age;
    int personID;
    static int nextID;
public:
    Person() : name("John Doe"), age(0) {
        personID = ++nextID;
    }
    Person(const string& name, int age) : name(name), age(age) {
        personID = ++nextID;
    }
    ~Person() {
        cout << "~Person() is called" << endl;
    }
    void displayDetails() const {
        cout << name << ", Age: " << age << ", P_ID: " << personID << endl;
    }
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    int getPersonID() const {
        return personID;
    }
    void setName(const string& name) {
        this->name = name;
    }
    void setAge(int age) {
        this->age = age;
    }
    bool operator==(const Person& other) const {
        return (name == other.name && age == other.age);
    }
    friend ostream& operator<<(ostream& os, const Person& p);
};
int Person::nextID = 0;
ostream& operator<<(ostream& os, const Person& p) {
    os << p.name << ", Age: " << p.age << ", P_ID: " << p.personID << endl;
    return os;
}


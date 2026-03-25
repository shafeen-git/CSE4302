#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <exception>
#include <cstring>
using namespace std;

class FileOpenException : public exception {
private:
    string message;
public:
    FileOpenException(const string &fileName) {
        message = "FileOpenException: Unable to open file '" + fileName + "'";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class MalformedPatientRecordException : public exception {
private:
    string message;
public:
    MalformedPatientRecordException(const string &line) {
        message = "MalformedPatientRecordException: Cannot deserialize line: '" + line + "'";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class DuplicatePatientIDException : public exception {
private:
    string message;
public:
    DuplicatePatientIDException(int id) {
        message = "DuplicatePatientIDException: Patient ID " + to_string(id) + " already exists";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidContactException : public exception {
private:
    string message;
public:
    InvalidContactException(const string &contact) {
        message = "InvalidContactException: Contact '" + contact + "' is invalid (must be 10 digits)";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Patient {
private:
    int id;
    string name;
    int age;
    char gender;
    string bloodGroup;
    string contact;

    bool isValidContact(const string &c) const {
        if (c.length() != 10) return false;
        for (char ch : c) {
            if (!isdigit(ch)) return false;
        }
        return true;
    }

public:
    Patient() : id(0), name(""), age(0), gender('M'), bloodGroup(""), contact("") {}

    Patient(int id, string name, int age, char gender, string bloodGroup, string contact)
        : id(id), name(name), age(age), gender(gender), bloodGroup(bloodGroup), contact(contact) {
        if (!isValidContact(contact)) {
            throw InvalidContactException(contact);
        }
    }

    ~Patient() {}

    int getId() const { return id; }

    string serialize() const {
        return to_string(id) + "|" + name + "|" + to_string(age) + "|" + gender + "|" + bloodGroup + "|" + contact;
    }

    static bool deserialize(const string &line, Patient &out) {
        try {
            int pos1 = line.find('|');
            if (pos1 == string::npos) throw MalformedPatientRecordException(line);
            out.id = stoi(line.substr(0, pos1));

            int pos2 = line.find('|', pos1 + 1);
            if (pos2 == string::npos) throw MalformedPatientRecordException(line);
            out.name = line.substr(pos1 + 1, pos2 - pos1 - 1);

            int pos3 = line.find('|', pos2 + 1);
            if (pos3 == string::npos) throw MalformedPatientRecordException(line);
            out.age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));

            int pos4 = line.find('|', pos3 + 1);
            if (pos4 == string::npos) throw MalformedPatientRecordException(line);
            out.gender = line[pos3 + 1];

            int pos5 = line.find('|', pos4 + 1);
            if (pos5 == string::npos) throw MalformedPatientRecordException(line);
            out.bloodGroup = line.substr(pos4 + 1, pos5 - pos4 - 1);

            out.contact = line.substr(pos5 + 1);
            if (!out.isValidContact(out.contact)) {
                throw InvalidContactException(out.contact);
            }
            return true;
        }
        catch (const exception &e) {
            throw;
        }
    }

    void printRow(ostream &os) const {
        os << "| " << setw(2) << left << id << " | ";
        os << setw(20) << left << name << " | ";
        os << setw(3) << left << age << " | ";
        os << setw(1) << left << gender << " | ";
        os << setw(5) << left << bloodGroup << " | ";
        os << setw(15) << left << contact << " |" << endl;
    }

    static void printHeader(ostream &os) {
        os << "---------------------------------------------------------------" << endl;
        os << "| " << setw(2) << left << "ID" << " | ";
        os << setw(20) << left << "Name" << " | ";
        os << setw(3) << left << "Age" << " | ";
        os << setw(1) << left << "G" << " | ";
        os << setw(5) << left << "Blood" << " | ";
        os << setw(15) << left << "Contact" << " |" << endl;
        os << "---------------------------------------------------------------" << endl;
    }
};

template <typename T, int MAX>
class FileRepository {
private:
    T items[MAX];
    int currSize;
    string fileName;

    bool isDuplicateID(int id) const {
        for (int i = 0; i < currSize; i++) {
            if (items[i].getId() == id) {
                return true;
            }
        }
        return false;
    }

public:
    FileRepository(const string fName) : currSize(0), fileName(fName) {}

    bool add(const T &item) {
        if (isDuplicateID(item.getId())) {
            throw DuplicatePatientIDException(item.getId());
        }

        if (currSize >= MAX) {
            throw bad_alloc();
        }

        ofstream file(fileName, ios::app);
        if (!file.is_open() || file.fail()) {
            throw FileOpenException(fileName);
        }
        file << item.serialize() << endl;
        file.close();

        items[currSize] = item;
        currSize++;
        return true;
    }

    int load() {
        ifstream file(fileName);
        if (!file.is_open() || file.fail()) {
            throw FileOpenException(fileName);
        }

        string line;
        currSize = 0;
        while (getline(file, line) && currSize < MAX) {
            if (!line.empty()) {
                T item;
                try {
                    if (T::deserialize(line, item)) {
                        if (isDuplicateID(item.getId())) {
                            throw DuplicatePatientIDException(item.getId());
                        }
                        items[currSize] = item;
                        currSize++;
                    }
                }
                catch (const exception &e) {
                    file.close();
                    throw;
                }
            }
        }
        file.close();
        return currSize;
    }

    void printAll(ostream &os) const {
        T::printHeader(os);
        for (int i = 0; i < currSize; i++) {
            items[i].printRow(os);
        }
        os << "---------------------------------------------------------------" << endl;
    }

    int count() const {
        return currSize;
    }
};

int main() {
    try {
        FileRepository<Patient, 100> repo("patients.txt");

        Patient p1(1, "Alice Johnson", 21, 'F', "O+", "0123456789");
        Patient p2(2, "Bob Khan", 23, 'M', "A-", "0987654321");

        repo.add(p1);
        repo.add(p2);

        repo.load();

        repo.printAll(cout);
        cout << "Loaded data for " << repo.count() << " patients from patients.txt" << endl;

        cerr << "\n--- Testing Exception Handling ---" << endl;

        try {
            Patient invalidContact(3, "Test User", 25, 'M', "B+", "12345");
            repo.add(invalidContact);
        }
        catch (const InvalidContactException &e) {
            cerr << "Caught: " << e.what() << endl;
        }

        try {
            Patient duplicate(1, "Duplicate Person", 30, 'F', "AB+", "9876543210");
            repo.add(duplicate);
        }
        catch (const DuplicatePatientIDException &e) {
            cerr << "Caught: " << e.what() << endl;
        }

        return 0;
    }
    catch (const FileOpenException &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (const MalformedPatientRecordException &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (const DuplicatePatientIDException &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (const InvalidContactException &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (const bad_alloc &e) {
        cerr << "Error: Memory allocation failed - " << e.what() << endl;
        return 1;
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}



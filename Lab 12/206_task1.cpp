#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
using namespace std;

class Patient{
private:
    int id;
    string name;
    int age;
    char gender;
    string bloodGroup;
    string contact;
public:
    Patient(int ID=0,string na="N/A",int ag=0,char gen='U',string bgroup="N/A",string cont="N/A"){
        id=ID;
        name=na;
        age=ag;
        gender=gen;
        bloodGroup=bgroup;
        contact=cont;
    }
    ~Patient()=default;

    string serialize() const{
        stringstream ss;
        ss<<id<<"|"<<name<<"|"<<age<<"|"<<gender<<"|"<<bloodGroup<<"|"<<contact;
        return ss.str();
    }

    static bool deserialize(const string &line,Patient &out){
        string token;
        vector<string> parts;
        parts.reserve(6);
        stringstream ss(line);
        while(getline(ss,token,'|')){
            parts.push_back(token);
        }
        if(parts.size()!=6) return false;
        try{
            out.id=stoi(parts[0]);
            out.name=parts[1];
            out.age=stoi(parts[2]);
            if(parts[3].size()!=1) return false;
            out.gender=parts[3][0];
            out.bloodGroup=parts[4];
            out.contact=parts[5];
        }catch(...){
            return false;
        }
        return true;
    }

    void printRow(ostream &os) const{
        os<<"| "<<setw(3)<<left<<id
          <<"| "<<setw(20)<<left<<name
          <<"| "<<setw(3)<<left<<age
          <<"| "<<setw(1)<<left<<gender
          <<" | "<<setw(6)<<left<<bloodGroup
          <<" | "<<setw(13)<<left<<contact
          <<"|"<<'\n';
    }

    static void printHeader(ostream &os){
        os<<string(63,'-')<<'\n';
        os<<"| "<<setw(3)<<left<<"ID"
          <<"| "<<setw(20)<<left<<"Name"
          <<"| "<<setw(3)<<left<<"Age"
          <<"| "<<setw(1)<<left<<"G"
          <<" | "<<setw(6)<<left<<"Blood"
          <<" | "<<setw(13)<<left<<"Contact"
          <<"|"<<'\n';
        os<<string(63,'-')<<'\n';
    }

    static void printFooter(ostream &os){
        os<<string(63,'-')<<'\n';
    }

    int getId() const{return id;}
};

bool appendPatientToFile(const string &fileName,const Patient &p){
    ofstream out(fileName,ios::app);
    if(!out.is_open()||out.fail()) return false;
    out<<p.serialize()<<'\n';
    return true;
}

int loadAllPatients(const string &fileName,Patient arr[],int maxCount){
    ifstream in(fileName);
    if(!in.is_open()||in.fail()) return 0;
    string line;
    int count=0;
    while(getline(in,line) && count<maxCount){
        if(line.empty()) continue;
        Patient temp;
        if(Patient::deserialize(line,temp)){
            arr[count]=temp;
            count++;
        }
    }
    return count;
}

int main(){
    const string fileName="patients.txt";
    ofstream clr(fileName,ios::trunc);
    clr.close();
    Patient p1(1,"Alice Johnson",21,'F',"O+","0123456789");
    Patient p2(2,"Bob Khan",23,'M',"A-","0987654321");
    appendPatientToFile(fileName,p1);
    appendPatientToFile(fileName,p2);

    Patient arr[100];
    int n=loadAllPatients(fileName,arr,100);

    Patient::printHeader(cout);
    for(int i=0;i<n;i++){
        arr[i].printRow(cout);
    }
    Patient::printFooter(cout);
    cout<<"Loaded data for "<<n<<" patients from "<<fileName<<'\n';
    return 0;
}

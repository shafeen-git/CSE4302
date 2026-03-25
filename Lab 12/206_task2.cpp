#include<fstream>
#include<bits/stdc++.h>
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
    Patient(int ID=0,string na="",int ag=-1,char gen='M',string bgroup="non",string cont="j"){
        id=ID;
        name=na;
        age=ag;
        gender=gen;
        bloodGroup=bgroup;
        contact=cont;
    }
    string serialization() const{
        char l='|';
        string s=to_string(id)+l+name+l+to_string(age)+l+gender+l+bloodGroup+l+contact+l;
        return s;
    }
    static bool deserialize(const string &line, Patient &out){
        int infonum=0;
        for(int i=0;i<line.size();i++){
            string info="";
            while(line[i]!='|'){
                info+=line[i];
                i++;
            }
            if(infonum==0){
                out.id=stoi(info);
            }
            if(infonum==1){
                out.name=info;
            }
            if(infonum==2){
                out.age=stoi(info);
            }
            if(infonum==3){
                out.gender=info[0];
            }
            if(infonum==4){
                out.bloodGroup=info;
            }
            if(infonum==5){
                out.contact=info;
            }
            infonum++;
        }
        return true;
    }
    void printRow(ostream &os){
        os << "|" << id << "|" << name << " |" << age << " |" << gender << "      |" << bloodGroup << "          |" << contact << "      |" << endl;
    }
    static void printHeader(ostream &os){
        os << "|" << "id" << "|" << "Name" << "|" << "age| gender| bloodGroup | Contact |" << endl;
    }
    ~Patient(){

    }
};
bool appendPatientToFile(const string &fileName,const Patient &p){
    string s=p.serialization();
    ofstream out(fileName,ios_base::app);
    if(out){
        out << s << endl;
    }
    else{
        return false;
    }
    out.close();
    return true;
}
int loadAllPatients(const string &fileName, Patient arr[], int maxCount){
    ifstream in(fileName);
    string s;
    int i=0;
    while(getline(in,s) && i<maxCount){
        arr[i].deserialize(s,arr[i]);
        i++;
    }
    return 1;
}
template<class T,int max>
class FileRepository{
   private:
   T items[max];
   int currSize;
   string fileName;
   public:
   FileRepository(const string FileName="NewFile"):fileName(FileName){
      currSize=0;
   }
   bool add(const T &item){
      ofstream out(fileName,ios_base::app);

      if(out && currSize<max){
        out << item.serialization() << endl;
        //items[currSize]=item;
        currSize++;
        return true;
      }
      else{
        return false;
      }
   }
   int load(){
     ifstream in(fileName);
     string s;
     int i=0;
     while(getline(in,s) && i<currSize){
        items[i].deserialize(s,items[i]);
        i++;
     }
     return i;
   }
   int Count () const{
     return currSize;
   }
   void printAll(ostream &os){
      items[0].printHeader(cout);
      for(int i=0;i<currSize;i++){
          items[i].printRow(cout);
      }
   }
};
int main(){
    Patient p1(12,"bob",18,'M',"A+","123");
    Patient p2(12,"god",10,'F',"B-","656");
    FileRepository<Patient,100> repo("PatientHealth.txt");
    repo.add(p1);
    repo.add(p2);
    repo.load();
    repo.printAll(cout);
    return 0;
}


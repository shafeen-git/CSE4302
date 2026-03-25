#include <bits/stdc++.h>
using namespace std;
class DisplayUnit{
private:
    float screenSize;
    string resolution;
public:
    DisplayUnit(float screenSize=55.08,string resolution="4K"):screenSize(screenSize),resolution(resolution){}
    float getScreenSize()const{return screenSize;}
    string getResolution()const{return resolution;}
    void setScreenSize(float s){screenSize=s;}
    void setResolution(const string& r){resolution=r;}
    void showVisuals() const{
        cout<<"Displaying content at "<<resolution<<" on " <<screenSize<<" inches screen.\n";
    }
    virtual ~DisplayUnit(){
        cout << "Display Unit turned off.\n";
    }
};
class ComputingUnit{
private:
    string processorModel;
    int ramSize;
public:
    ComputingUnit(string processorModel="Snapdragon",int ramSize=4):processorModel(processorModel),ramSize(ramSize){}
    string getProcessorModel()const{return processorModel;}
    int getRamSize()const{return ramSize;}
    void setProcessorModel(const string& p){processorModel=p;}
    void setRamSize(int r){ramSize=r;}
    void processStream()const{
        cout <<"Decoding video stream using "<< processorModel<< " (" << ramSize << " GB RAM).\n";
    }
    virtual ~ComputingUnit(){
        cout << "Computing Unit turned off.\n";
    }
};
class Speaker{
private:
    int wattage;
    string position;
public:
    Speaker(int wattage=10,string position="Left"):wattage(wattage),position(position){}
    int getWattage()const{return wattage;}
    string getPosition()const{return position;}
    void setWattage(int w){wattage=w;}
    void setPosition(const string& p){position = p;}
    void emitSound() const{
        cout <<"Boom! Sound coming from "<< position<< " speaker at " << wattage << " watts.\n";
    }
    ~Speaker(){
        cout << position << " Speaker turned off.\n";
    }
};
class SmartTV: public DisplayUnit,public ComputingUnit{
private:
    string brandName;
    Speaker speakers[2];
public:
    SmartTV(float screenSize,string resolution,string processorModel,int ramSize,string brandName,int speakerWattage): DisplayUnit(screenSize, resolution),ComputingUnit(processorModel, ramSize),brandName(brandName),speakers{ Speaker(speakerWattage, "Left"), Speaker(speakerWattage, "Right") } {}
    void watchMovie(){
        cout << "- - - Starting movie on " << brandName << " TV - - -\n";
        showVisuals();
        processStream();
        int i;
        for(i=0;i<2;i++){
            speakers[i].emitSound();
        }
    }
    ~SmartTV(){
        cout << brandName << " TV turned off.\n";
    }
};
int main(){
    SmartTV tv(55.08,"4K","Snapdragon",4,"Sony",20);
    tv.watchMovie();
}

#include <bits/stdc++.h>
using namespace std;
class IGadget{
public:
    virtual void turnOn()=0;
    virtual void turnOff()=0;
    virtual ~IGadget()=default;
};
class IConnected{
public:
    virtual void connectToWiFi(string ssid)=0;
    virtual void disconnectWiFi()=0;
    virtual ~IConnected()=default;
};
class BasicGadget:public IGadget{
protected:
    string gadgetName;
public:
    BasicGadget(string gadgetName="Unnamed"):gadgetName(gadgetName){}
    void turnOn() override{cout<<"Basic Turn on\n";}
    void turnOff() override{cout<<"Basic Turn off\n";}
    void showName() const{
        cout<<"Gadget name: "<<gadgetName<<"\n";
    }
};
class SmartGadget:public IGadget,public IConnected{
protected:
    string gadgetName;
    int batteryLevel;
public:
    SmartGadget(string gadgetName="Unnamed",int batteryLevel=67):gadgetName(gadgetName),batteryLevel(batteryLevel){}
    void turnOn() override{
        cout<<"Smart Turn on\n";
        cout<<"Battery level: "<<batteryLevel<<"%\n";
    }
    void turnOff() override{
        cout<<"Smart Turn off\n";
    }
    void connectToWiFi(string ssid) override{
        cout<<"Connected to WiFi: "<<ssid<<"\n";
    }
    void disconnectWiFi() override{
        cout<<"WiFi disconnected\n";
    }
    void chargeBattery(int amount){
        batteryLevel+=amount;
        if(batteryLevel>100)batteryLevel=100;
        cout<<"Battery level: "<<batteryLevel<<"%\n";
    }
    void reduceBattery(int amount){
        batteryLevel-=amount;
        if(batteryLevel<0)batteryLevel=0;
        cout<<"Battery level: "<<batteryLevel<<"%\n";
    }
    int getBatteryLevel()const{
        return batteryLevel;
    }
};
class AdvancedRobot:public SmartGadget{
    string robotID;
public:
    AdvancedRobot(string gadgetName="Unnamed",string robotID="00",int batteryLevel=67):SmartGadget(gadgetName,batteryLevel),robotID(robotID){}
    void turnOn() override{
        SmartGadget::turnOn();
        cout<<"Robot "<<robotID<<" is powered up\n";}
    void scanEnvironment(){
        cout<<"Scanning the environment...\n";
    }
    void moveForward(int steps){
        cout<<"Robot "<<robotID<<" moved "<<steps<<" steps forward\n";
    }
    void performSelfCheck(){
        cout<<"Robot "<<robotID<<" performing self-check...\n";
    }
};

void test(IGadget *t){
    t->turnOn();
    t->turnOff();
}
int main(){
    AdvancedRobot r("Robot1","01");
    r.turnOn();
    r.chargeBattery(20);
    r.connectToWiFi("HomeWiFi");
    r.scanEnvironment();
    r.moveForward(5);
    r.performSelfCheck();
    r.disconnectWiFi();
    r.turnOff();
    cout<<"Battery level: "<<r.getBatteryLevel()<<"%\n";
    r.reduceBattery(10);

    BasicGadget b("BasicOne");
    SmartGadget s("SmartOne");
    AdvancedRobot a("Robot2","02");

    test(&b);
    test(&s);
    test(&a);
}

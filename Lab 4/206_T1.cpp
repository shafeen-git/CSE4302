#include<bits/stdc++.h>
using namespace std;
class SmartElevator{
private:
    int curflno;
    double curtotw;
    int maxfl;
public:
    SmartElevator(int maxflno){
        curflno=0;
        curtotw=0;
        maxfl=maxflno;
    }
    ~SmartElevator(){
        cout<<"Elevator system entering maintenance mode."<<"\n";
    }
    void boardPassenger(double passw){
        double neww;
        neww=curtotw+passw;
        if(neww>4302.0){
            cout<<"Overload! Someone must exit."<<"\n";
        }
        else{
            curtotw=neww;
        }
    }
    void goToFloor(int targf){
        if((targf<0)||(targf>maxfl)){
            cout<<"Error 404: Floor not found. Try reality instead."<<"\n";
        }
        else if(targf==curflno){
            cout<<"Staying put engaged. Enjoy the view!"<<"\n";
        }
        else{
            curflno=targf;
        }
    }
    void displayPanel()const{
        cout<<"Current floor: "<<curflno<<", Current load: "<<curtotw<<" kg"<<"\n";
    }
};

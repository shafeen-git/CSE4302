#include <bits/stdc++.h>
using namespace std;
class BatteryMonitor{
private:
    double battery;
    double criticalThreshold;
public:
    BatteryMonitor(){
        battery=100.0;
        criticalThreshold=15.0;
    }
    void setCriticalThreshold(double percent){
        if((percent < 5.0) || (percent > 25.0)){
            cout << "Invalid threshold; must be 5-25%" <<"\n";
            return;
        }
        criticalThreshold=percent;
    }
    void drain(double amount){
        if(amount < 0){
            cout << "Invalid drain amount" <<"\n";
            return;
        }
        battery-=amount;
        if (battery < 0){
            battery=0;
            cout << "Battery depleted"<<"\n";
        }
    }
    void recharge(double amount){
        if(amount < 0){
            cout << "Invalid recharge amount" <<"\n";
            return;
        }
        battery+=amount;
        if (battery>100) {
            battery=100;
            cout << "Battery fully charged" <<"\n";
        }
    }
    bool needsCharging(){
        return battery <= criticalThreshold;
    }
    void status(){
        cout << fixed << setprecision(1);
        cout <<"Battery: "<<battery << "% "<<"[" << (needsCharging()?"CRITICAL":"OK")<<"]"<"\n";
    }
};


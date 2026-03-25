#include <bits/stdc++.h>
using namespace std;
class BatchMeter{
private:
    int total,pulseSize;
public:
    BatchMeter(){
        total=0;
        pulseSize=1;
    }
    void setPulseSize(int s){
        if(s > 0){
            pulseSize=s;
        }
        else{
            cout <<"Invalid pulse; must be > 0"<<"\n";
        }
    }
    int getTotal(){
        return total;
    }
    void addPulse(){
        total+=pulseSize;
    }
    void getClear(){
        total=0;
    }
};

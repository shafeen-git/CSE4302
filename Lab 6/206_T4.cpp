#include<bits/stdc++.h>
using namespace std;
class TradeSignal{
private:
    double magnitude;
    long timestamp;
public:
    TradeSignal(){
        magnitude=0.0;
        timestamp=0;
    }
    TradeSignal(double m,long t){
        setMagnitude(m);
        setTimestamp(t);
    }
    ~TradeSignal(){
        cout<<"[Signal destroyed at timestamp "<<timestamp<<"]\n";
    }
    double getMagnitude()const{return magnitude;}
    long getTimestamp()const{return timestamp;}
    void setMagnitude(double m){
        if(m<0){
            cout<<"Invalid magnitude\n";
            return;
        }
        magnitude=m;
    }
    void setTimestamp(long t){
        if(t<0){
            cout<<"Invalid timestamp\n";
            return;
        }
        timestamp=t;
    }
    TradeSignal operator+(const TradeSignal &other)const{
        double newMag=magnitude+other.magnitude;
        long newTime=(timestamp>other.timestamp)?timestamp:other.timestamp;
        return TradeSignal(newMag,newTime);
    }
    TradeSignal operator*(double scalar)const{
        if(scalar<0){
            cout<<"Invalid scalar\n";
            return *this;
        }
        return TradeSignal(magnitude*scalar,timestamp);
    }
    friend ostream& operator<<(ostream &out,const TradeSignal &s){
        out<<"["<<s.timestamp<<"] Magnitude: "
           <<fixed<<setprecision(2)<<s.magnitude;
        return out;
    }
    friend TradeSignal operator*(double scalar,const TradeSignal &s){
        return s*scalar;
    }
};

int main(){
    TradeSignal s1(10.5,10001);
    TradeSignal s2=s1*2.0;
    TradeSignal s3=3.0*s1;
    TradeSignal s4=s2+s3;
    cout<<s4<<"\n";
}


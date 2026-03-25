#include <bits/stdc++.h>
using namespace std;
class StopWatch{
private:
    int hours;
    int minutes;
    int seconds;
    void settime(){
        if(seconds>=60){
            minutes+=seconds/60;
            seconds%=60;
        }
        if(minutes>=60){
            hours+=minutes/60;
            minutes%=60;
        }
        if(hours>=24){
            hours%=24;
        }
    }
public:
    StopWatch(){
        hours=0;
        minutes=0;
        seconds=0;
    }
    StopWatch(int h,int m,int s){
        hours=h;
        minutes=m;
        seconds=s;
        settime();
    }
    ~StopWatch(){
        cout<<"StopWatch destroyed at ";cout<<setw(2)<<setfill('0')<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds<<"\n";
    }
    int getHours()const{
        return hours;
    }
    int getMinutes()const{
        return minutes;
    }
    int getSeconds()const{
        return seconds;
    }
    void setHours(int h){
        if(h<0){
            cout<<"Invalid hours\n";
            return;
        }
        hours=h%24;
    }
    void setMinutes(int m){
        if(m<0){
            cout<<"Invalid minutes\n";
            return;
        }
        minutes=m;
        settime();
    }
    void setSeconds(int s){
        if(s<0){
            cout<<"Invalid seconds\n";
            return;
        }
        seconds=s;
        settime();
    }
    StopWatch& operator++(){
        seconds++;
        settime();
        return *this;
    }
    StopWatch operator++(int){
        StopWatch old=*this;
        ++(*this);
        return old;
    }
    void read(){
        cin>>hours>>minutes>>seconds;
        settime();
    }
    void print()const{
        cout<<setw(2)<<setfill('0')<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds;
    }
};
int main(){
    StopWatch s1;
    cout<<"Enter time (H M S): ";
    s1.read();
    cout<<"Initial time: ";
    s1.print();
    cout<<"\n";
    ++s1;
    cout<<"After ++s1: ";
    s1.print();
    cout<<"\n";
    StopWatch old=s1++;
    cout<<"Old snapshot: ";
    old.print();
    cout<<"\n";
    cout<<"Current time: ";
    s1.print();
    cout<<"\n";
}

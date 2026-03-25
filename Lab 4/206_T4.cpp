#include<bits/stdc++.h>
using namespace std;
class CreditCard{
private:
    const double limit;
    double balance;
public:
    CreditCard(double lim){
        limit=lim;
        balance=0.0;
    }
    ~CreditCard(){
        cout<<"Card destroyed"<<"\n";
    }
    void makePurchase(double amnt){
        if(balance+amnt>limit){
            cout<<"Declined"<<"\n";
        }
        else{
            balance+=amnt;
        }
    }
    bool compareAvailability(const CreditCard &obj)const{
        double availc,objc,res;
        availc=limit-balance;
        objc=obj.limit-obj.balance;
        res=availc-objc;
        return res;
    }
    void displayInfo()const{
        cout<<"Limit: "<<limit<<"\n"<<"Balance: "<<balance<<"\n"<<"Available: "<<limit-balance<<"\n";
    }
};


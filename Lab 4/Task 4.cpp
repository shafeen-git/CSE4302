#include<iostream>
using namespace std;
class CreditCard{
private:
    const double limit;
    double balance;
public:
    CreditCard(double lim):limit(lim),balance(0.0){}~CreditCard(){
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
    bool compareAvailability(const CreditCard &other)const{
        double v,av,res;
        v=limit-balance;
        av=other.limit-other.balance;
        res=v-av;
        return res;
    }
    void displayInfo()const{
        cout<<"Limit: "<<limit<<", Balance: "<<balance<<", Available: "<<limit-balance<<"\n";
    }
};


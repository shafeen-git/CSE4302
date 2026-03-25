#include <bits/stdc++.h>
using namespace std;
class DigitalWallet{
private:
    string ID;
    double balance;
    bool isOverdraft(double b)const{
        if(b<0.0){
            return true;
        }
        else return false;
    }
public:
    DigitalWallet(const string &id,double initialBalance){
        setID(id);
        setBalance(initialBalance);
    }
    ~DigitalWallet(){
        cout<<"Logged ID="<<ID<<" "<<"FinalBalance="<<balance<<"\n";
    }
    const string& getID()const{
        return ID;
    }
    double getBalance()const{
        return balance;
    }
    void setID(const string &id){
        if(id.size()==0){
            cout<<"Invalid ID\n";
            return;
        }
        ID=id;
    }
    void setBalance(double b){
        if(b<0){
            cout<<"Invalid balance\n";
            return;
        }
        balance=b;
    }
    void checkStatus()const{
        if(isOverdraft(balance)){
            cout<<"Status:OVERDRAFT\n";
        }
        else cout<<"Status:OK\n";
    }
    DigitalWallet operator+(double amount)const{
        DigitalWallet res(*this);
        if(amount<0){
            cout<<"Invalid deposit\n";
            return res;
        }
        res.balance=balance+amount;
        return res;
    }
    DigitalWallet operator-(double amount)const{
        DigitalWallet res(*this);
        if(amount<0){
            cout<<"Invalid withdrawal\n";
            return res;
        }
        res.balance=balance-amount;
        if(res.isOverdraft(res.balance)){
            cout<<"Warning:Overdraft occurred\n";
        }
        return res;
    }
    DigitalWallet operator*(double rate)const{
        DigitalWallet res(*this);
        if(rate<0){
            cout<<"Invalid rate\n";
            return res;
        }
        res.balance=balance*rate;
        if(res.isOverdraft(res.balance)){
            cout<<"Warning:Overdraft occurred\n";
        }
        return res;
    }
    operator long()const{
        return (long)llround(balance*100.0);
    }
    friend DigitalWallet operator+(double amount,const DigitalWallet &w){
        return w+amount;
    }
};
int main(){
    DigitalWallet w1("230041206",5.50);
    DigitalWallet w2;
    w1.checkStatus();
    w2=w1+50.0;
    cout<<"w2 balance:"<<w2.getBalance()<<"\n";
    w2=50.0+w1;
    cout<<"w2 balance:"<<w2.getBalance()<<"\n";
    w2=w1-12.50;
    cout<<"w2 balance:"<<w2.getBalance()<<"\n";
    w2.checkStatus();
    w2=w1*1.05;
    cout<<"w2 balance:"<<w2.getBalance()<<"\n";
    long totalCents=w1;
    cout<<"w1 cents:"<<totalCents<<"\n";
}


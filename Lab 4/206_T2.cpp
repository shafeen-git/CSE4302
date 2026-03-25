#include<bits/stdc++.h>
using namespace std;
class TaxEstimator{
private:
    double totali;
    double totald;
    float determineBracketRate() const{
        double neti=totali-totald;
        if(neti<10000){
            return 0.0f;
        }
        else if(neti<=50000){
            return 10.0f;
        }
        else return 20.0f;
    }
public:
    TaxEstimator():totali(0.0),totald(0.0){}
    ~TaxEstimator(){
         cout<<"Tax session closed."<<"\n";
    }
    void addIncomeSource(double amnt){
        if(amnt<=0.0){
            cout<<"Negative income is bad for the economy and my code."<<"\n";
        }
        else{
            totali+=amnt;
        }
    }
    void addExpense(double amnt){
        totald+=amnt;
    }
    void printTaxSlip()const{
        double neti,taxdue;
        float rate;
        neti=totali-totald;
        if(neti<0.0){
            neti=0.0;
        }
        rate=determineBracketRate();
        taxdue=neti*rate/100.0;
        cout<<"Tax due: "<<taxdue<<"\n";
    }
};







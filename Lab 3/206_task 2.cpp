#include <iostream>
using namespace std;
class RatioQuota{
private:
    int p;
    int q;
public:
    RatioQuota(){
        p=1;
        q=1;
    }
    void setRatio(int num,int den){
        p=num;
        q=den;
        if(q == 0){
            cout <<"Denominator cannot be zero" <<"\n";
            return;
        }
    }
    double asDecimal(int p,int q){
        double ans=(double)p/(double)q;
        return ans;
    }
    void reciprocal(){
        int temp;
        if (p == 0) {
            cout << "Reciprocal failed: zero cannot be a denominator" << endl;
            return;
        }
        temp=p;
        p=q;
        q=temp;
    }
    void show(){
        cout <<"Ratio: "<<p<<"/"<<q<< endl;
    }
};


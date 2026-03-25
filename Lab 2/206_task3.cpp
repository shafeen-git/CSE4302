#include <bits/stdc++.h>
using namespace std;
struct fraction{
    int num;
    int den;
};
int main(){
    fraction f1,f2;
    int a,b,c,d;
    char dummycharacter;
    cout <<"Enter first fraction: ";
    cin>>f1.num>>dummycharacter>>f1.den;
    cout <<"Enter second fraction: ";
    cin>>f2.num>>dummycharacter>>f2.den;
    a=f1.num;
    b=f1.den;
    c=f2.num;
    d=f2.den;
    cout << "Sum = "<<((a*d) + (b*c))<<'/'<<(b*d);
}

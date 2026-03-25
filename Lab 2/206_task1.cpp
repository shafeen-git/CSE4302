#include <iostream>
using namespace std;
int main(){
    int a,b,c,d;
    char dummycharacter;
    cout <<"Enter first fraction: ";
    cin>>a>>dummycharacter>>b;
    cout <<"Enter second fraction: ";
    cin>>c>>dummycharacter>>d;
    cout << "Sum = "<<((a*d) + (b*c))<<'/'<<(b*d);
}

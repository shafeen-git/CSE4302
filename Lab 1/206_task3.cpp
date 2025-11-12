#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double deg;
    cout <<"Enter value in degrees:";
    cin >>deg;
    double ans;
    ans=(deg*3.141593)/180.0;
    cout <<"Value in radians:";
    cout<<setprecision(9)<<ans;
}

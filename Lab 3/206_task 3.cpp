#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class SnackProfile{
private:
    char itemName[50];
    char maker[50];
    double MRP;
    double discount;

public:
    SnackProfile(){
        itemName[0]='\0';
        maker[0]='\0';
        MRP=0.0;
        discount=7.0;
    }

    void setLabels(const char item[],const char make[]){
        strncpy(itemName,item,49);
        itemName[49]='\0';

        strncpy(maker,make,49);
        maker[49]='\0';
    }

    void setMRP(double price){
        if(price<0){
            MRP=0.0;
            cout<<"Invalid MRP; set to 0.0\n";
            return;
        }
        MRP=price;
    }

    void setDiscount(double percent){
        if(percent<0||percent>25){
            return;
        }
        discount=percent;
    }

    double getUnitPrice()const{
        return MRP*(1.0-discount/100.0);
    }

    double getTotalPrice(int qty=1)const{
        if(qty<0){
            cout<<"Invalid quantity\n";
            return 0.0;
        }
        return getUnitPrice()*qty;
    }

    void info()const{
        cout<<fixed<<setprecision(2);
        cout<<"["<<itemName<<"] by ["<<maker<<"]: "
            <<"MRP "<<MRP<<", Discount "<<discount
            <<"%, Unit "<<getUnitPrice()<<"\n";
    }
};

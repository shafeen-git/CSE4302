#include <bits/stdc++.h>
using namespace std;
class Pizza{
private:
    string pizzaName;
    string crustType;
    int spicinessLevel;
    bool isExtraCheesy;
public:
    Pizza(){
        pizzaName="Unnamed";
        crustType="Thin";
        spicinessLevel=0;
        isExtraCheesy=false;
    }
    Pizza(string pizzaname,string crusttype,int spicelevel,bool extracheesy){
        setPizzaName(pizzaname);
        setCrustType(crusttype);
        setSpicinessLevel(spicelevel);
        setIsExtraCheesy(extracheesy);
    }
    string getPizzaName()const{
        return pizzaName;
    }
    string getCrustType()const{
        return crustType;
    }
    int getSpicinessLevel()const{
        return spicinessLevel;
    }
    bool getIsExtraCheesy()const{
        return isExtraCheesy;
    }
    void setPizzaName(const string &pizzaname){
        pizzaName = pizzaname;
    }
    void setCrustType(const string &crusttype){
        if(crusttype == "Thin" || crusttype == "Thick" || crusttype == "Stuffed"){
            crustType=crusttype;
        }
        else{
            crustType="Thin";
        }
    }
    void setSpicinessLevel(int spicelevel){
        if(spicelevel >= 1 && spicelevel <= 10){
            spicinessLevel=spicelevel;
        }
        else{
            spicinessLevel=5;
        }
    }
    void setIsExtraCheesy(bool extracheesy){
        isExtraCheesy=extracheesy;
    }
    void display()const{
        cout <<"Pizza Name: "<<pizzaName<<"\n";
        cout <<"Crust Type: "<< crustType <<"\n";
        cout <<"Spiciness Level: "<< spicinessLevel << "\n";
        cout <<"Extra Cheesy: "<< (isExtraCheesy ? "Yes" : "No") << "\n";
    }
};
void prepareOrders(Pizza menu[],int size){
    int i,spice,randomSpice,extraInput;
    bool extra;
    string name,crust;
    for (i=0;i<4 && i<size;i++){
        cout <<"Pizza name: ";
        cin.ignore();
        getline(cin,name);
        cout <<"Crust type: ";
        getline(cin,crust);
        cout <<"Spiciness level: ";
        cin >> spice;
        cout <<"Is extra cheesy: ";
        cin >> extraInput;
        if(extraInput==1){
            extra=true;
        }
        else extra=false;
        menu[i].setPizzaName(name);
        menu[i].setCrustType(crust);
        menu[i].setSpicinessLevel(spice);
        menu[i].setIsExtraCheesy(extra);
    }
    for (i=4;i<size;i++){
        menu[i].setPizzaName("Mystery Pizza");
        menu[i].setCrustType("Thick");
        randomSpice=(rand()%10)+1;
        menu[i].setSpicinessLevel(randomSpice);
        if (i%2==0){
            menu[i].setIsExtraCheesy(true);
        }
        else{
            menu[i].setIsExtraCheesy(false);
        }
    }
}
int main(){
    const int SIZE=30;
    int i;
    srand(time(0));
    Pizza menu[SIZE];
    prepareOrders(menu,SIZE);
    for(i=0;i<SIZE;i++){
        if (menu[i].getSpicinessLevel() >= 7) {
            menu[i].display();
        }
    }
}


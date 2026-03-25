#include <bits/stdc++.h>
using namespace std;
class Hero{
private:
    string heroName;
    string classType;
    int attackPower;
    int defensePower;
public:
    Hero(){
        heroName="Unknown";
        classType="None";
        attackPower=0;
        defensePower=0;
    }
    Hero(string name,string type,int atk,int def){
        heroName=name;
        classType=type;
        attackPower=atk;
        defensePower=def;
    }
    string getHeroName()const{
        return heroName;
    }
    string getClassType()const{
        return classType;
    }
    int getAttackPower()const{
        return attackPower;
    }
    int getDefensePower()const{
        return defensePower;
    }
    void setHeroName(string name){
        heroName=name;
    }
    void setClassType(string type){
        classType=type;
    }
    void setAttackPower(int atk){
        attackPower=atk;
    }
    void setDefensePower(int def){
        defensePower=def;
    }
    Hero spar(Hero opponent){
        double myAtk,myDef,opAtk,opDef,myE,opE;
        myDef=defensePower;
        opAtk=opponent.attackPower;
        opDef=opponent.defensePower;
        myE=pow(myAtk,0.7)*(myAtk/(myAtk+opDef))+pow(myDef,0.6)*(myDef/(myDef+opAtk));
        opE=pow(opAtk,0.7)*(opAtk/(opAtk+myDef))+pow(opDef,0.6)*(opDef/(opDef+myAtk));
        if(myE>=opE){
            return Hero(heroName,classType,attackPower,defensePower);
        }
        else return opponent;
    }
    void display()const{
        cout<<"Name: "<<heroName<<"\n";
        cout<<"Class: "<<classType<<"\n";
        cout<<"Attack: "<<attackPower<<"\n";
        cout<<"Defense: "<<defensePower<<"\n";
        cout<<"\n";
    }
};
int main(){
    int i;
    Hero heroes[5]={
        Hero("Shafeen","Warrior",80,50),
        Hero("Rakin","Mage",60,40),
        Hero("Dibbo","Rogue",75,35),
        Hero("Jameel","Paladin",55,60),
        Hero("Hania","Knight",70,65)
    };
    Hero winner=heroes[0];
    for(i=1;i<5;i++){
        winner=winner.spar(heroes[i]);
        cout << winner.heroName <<"\n";
    }
    cout<<" ULTIMATE CHAMPION \n";
    winner.display();
}

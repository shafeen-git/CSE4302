#include<iostream>
using namespace std;
class Zombie{
private:
    int health;
    static int hordeCount;
public:
    Zombie(int hp):health(hp){
        hordeCount++;
        cout<<"A new zombie rises! Total count: "<<hordeCount<<"\n";
    }
    ~Zombie(){
        hordeCount--;
        cout<<"Zombie eliminated. Total remaining: "<<hordeCount<<"\n";
    }
    void takeDamage(int dmg){
        health-=dmg;
        if(health<=0){
            health=0;
            cout<<"Zombie is 'down'"<<"\n";
        }
    }
    static int getHordeCount(){
        return hordeCount;
    }
};
int Zombie::hordeCount=0;

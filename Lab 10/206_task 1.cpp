#include<bits/stdc++.h>
using namespace std;
class SpellCaster{
protected:
    string casterName;
    int basePowerLevel;
    int health;
public:
    SpellCaster(string name="SpellCaster", int power=10,int hp=100){
        casterName = name;
        basePowerLevel = power;
        health = hp;
    }
    virtual int castSpell(){
        cout << casterName << " is casting a generic spell..." <<"\n";
        return basePowerLevel;
    }
    void scout(){
        cout << casterName << " is scouting the area for enemies." <<"\n";
    }
    virtual void takeDamage(int damage){
        health -= damage;
        if (health < 0) health = 0;
    }
    bool isAlive(){
        return health > 0;
    }
    string getName()const{return casterName;}
    int getHealth()const{return health;}
    virtual ~SpellCaster(){}
};
class Pyromancer : public SpellCaster {
protected:
    int heatIntensity;
public:
    Pyromancer(string name = "Pyromancer",int power=10, int hp = 100, int heat = 15) {
        casterName = name;
        basePowerLevel = power;
        health = hp;
        heatIntensity = heat;
    }
    int castSpell()override{
        int baseDamage = SpellCaster::castSpell();
        cout << "Adding fire element..." << endl;
        return baseDamage + heatIntensity;
    }
    void takeDamage(int damage) override {
        health -= (damage * 2);
        if (health < 0) health = 0;
    }
};
class LavaMage : public Pyromancer {
private:
    int magmaDensity;
public:
    LavaMage(string name = "LavaMage", int power = 10, int hp = 100, int heat = 15, int magma = 20) {
        casterName = name;
        basePowerLevel = power;
        health = hp;
        heatIntensity = heat;
        magmaDensity = magma;
    }
    int castSpell() override {
        int fireDamage = Pyromancer::castSpell();
        cout << "Solidifying magma..." << endl;
        return fireDamage + magmaDensity;
    }

    void ignite() {
        cout << "The ground is burning!" << endl;
    }

    void takeDamage(int damage) override {
        health -= (damage * 3);
        if (health < 0) health = 0;
    }
};
class Enemy {
protected:
    string name;
    int health;
    int armor;
public:
    Enemy(string n = "Generic Enemy", int hp = 60, int arm = 50) {
        name = n;
        health = hp;
        armor = arm;
    }
    virtual void takeDamage(int damage) {
        int actualDamage = damage - armor;
        if (actualDamage > 0) {
            health -= actualDamage;
        }
        if (health < 0) health = 0;
    }
    virtual string getType(){
        return "Enemy";
    }
    virtual int attack(){
        return 10;
    }
    bool isAlive(){
        return health > 0;
    }
    string getName()const{ return name; }
    int getHealth()const{ return health; }
    virtual ~Enemy(){}
};
class Ogre : public Enemy {
private:
    bool rageMode;
public:
    Ogre(string n = "Ogre", int hp = 60, int arm = 50) {
        name = n;
        health = hp;
        armor = arm;
        rageMode = false;
    }
    int attack() override {
        if (rageMode) {
            return 25;
        }
        return 20;
    }
    void takeDamage(int damage) override {
        int actualDamage = damage - armor;
        if (actualDamage > 0) {
            health -= actualDamage;
        }
        if (health < 0) health = 0;

        if (health < 5 && health > 0) {
            if (!rageMode) {
                rageMode = true;
                cout << name << " enters RAGE MODE!" << endl;
            }
        }
    }
    string getType()override {
        return "Ogre";
    }
};
int main(){
    SpellCaster* wizards[3];
    wizards[0] = new SpellCaster("Shafeen",25,78);
    wizards[1] = new Pyromancer("Rafat",15,68,20);
    wizards[2] = new LavaMage("Talha",10,60,15,22);
    cout << "=== Testing Polymorphic Spell Casting ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nWizard " << (i + 1) << ":" << endl;
        int damage = wizards[i]->castSpell();
        cout << "Total damage: " << damage << endl;
    }
    Enemy* enemies[3];
    enemies[0] = new Ogre("Ogre1", 60, 10);
    enemies[1] = new Ogre("Ogre2", 60, 10);
    enemies[2] = new Ogre("Ogre3", 60, 10);
}

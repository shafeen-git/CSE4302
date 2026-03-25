#include <bits/stdc++.h>
using namespace std;
class SpellCaster{
private:
    string casterName;
    int basePowerLevel;
public:
    SpellCaster(string name="Spellcaster",int basePower=10):casterName(name),basePowerLevel(basePower){}
    virtual int castSpell(){
        cout <<"["<<casterName<<"] is casting a generic spell...\n";
        return basePowerLevel;
    }
    void scout(){
        cout << "["<<casterName<<"] is scouting the area for enemies.\n";
    }
    virtual ~SpellCaster()=default;
};
class Pyromancer : public SpellCaster{
private:
    int heatIntensity;
public:
    Pyromancer(string name="Pyromancer",int basePower=15,int heat=25):SpellCaster(name,basePower),heatIntensity(heat){}
    int castSpell() override {
        int dmg=SpellCaster::castSpell();
        cout << "Adding fire element...\n";
        dmg += heatIntensity;
        return dmg;
    }
};
class LavaMage:public Pyromancer{
private:
    int magmaDensity;
public:
    LavaMage(string name="LavaMage",int basePower=10,int heat=5,int magma=7):Pyromancer(name,basePower,heat),magmaDensity(magma){}
    int castSpell()override{
        int dmg=Pyromancer::castSpell();
        cout << "Solidifying magma...\n";
        dmg += magmaDensity;
        return dmg;
    }
    void ignite(){
        cout << "The ground is burning!\n";
    }
};
int main(){
    string name;
    int basePower, heat, magma;
    cin >> name >> basePower >> heat >> magma;
    LavaMage mage(name, basePower, heat, magma);
    mage.scout();
    int finalDamage = mage.castSpell();
    cout << finalDamage << "\n";
    mage.ignite();
}

#include <bits/stdc++.h>
using namespace std;
class GymProfile{
private:
    string memberName;
    string membershipTier;
    double bodyWeight;
    double benchPressMax;
public:
    GymProfile(){
        memberName="N/A";
        membershipTier="N/A";
        bodyWeight=0;
        benchPressMax=0;
    }
    GymProfile(string name,string tier,double weight,double benchMax){
        setMemberName(name);
        setMembershipTier(tier);
        setBodyWeight(weight);
        setBenchPressMax(benchMax);
    }
    string getMemberName()const{
        return memberName;
    }
    string getMembershipTier()const{
        return membershipTier;
    }
    double getBodyWeight()const{
        return bodyWeight;
    }
    double getBenchPressMax()const{
        return benchPressMax;
    }
    void setMemberName(const string &name){
        memberName=name;
    }
    void setMembershipTier(const string &tier){
        if(tier.length()>3){
            membershipTier=tier;
        }
        else membershipTier="Standard";
    }
    void setBodyWeight(double weight){
        if(weight>=40 && weight<=200){
            bodyWeight=weight;
        }
        else bodyWeight=70;
    }
    void setBenchPressMax(double benchMax){
        benchPressMax=benchMax;
    }
    void display()const{
        cout<<"Name: "<<memberName<<"\n";
        cout<<"Tier: "<<membershipTier<<"\n";
        cout<<"Body Weight: "<<bodyWeight<<" kg\n";
        cout<<"Bench Press Max: "<<benchPressMax<<" kg\n";
        cout <<"\n";
    }
};
void completeTrainingSession(GymProfile &profile){
    double newBench,newWeight;
    newBench=profile.getBenchPressMax()*1.05;
    newWeight=profile.getBodyWeight()-1.5;
    profile.setBenchPressMax(newBench);
    profile.setBodyWeight(newWeight);
}
int main(){
    int i;
    const int SIZE=5;
    GymProfile profiles[SIZE]={
        GymProfile("Shafeen","Premium",65,60),
        GymProfile("Rakin","Gold",85,90),
        GymProfile("Issmam","Pro",75,80),
        GymProfile("Hania","VIP",55,50),
        GymProfile("Jameel","S",95,110)
    };
    cout<<"Before Training: \n";
    for(i=0;i<SIZE;i++){
        cout<<"Profile #"<<i<<":\n";
        profiles[i].display();
    }
    for(i=0;i<SIZE;i++){
        completeTrainingSession(profiles[i]);
    }
    cout<<"After Training: \n";
    for(i=0;i<SIZE;i++){
        cout<<"Profile #"<<i<<":\n";
        profiles[i].display();
    }
}


#include <bits/stdc++.h>
using namespace std;
class SocialPost{
private:
    string ID;
    int likes;
    int shares;
    int nonzero(int x)const{
        if(x<0){
            return 0;
        }
        else return x;
    }
public:
    SocialPost(){
        ID="N/A";
        likes=0;
        shares=0;
    }
    SocialPost(const string &id,int l,int s){
        ID=id;
        likes=nonzero(l);
        shares=nonzero(s);
    }
    ~SocialPost(){
        cout<<"[Post destroyed] "<<ID<<" Likes:"<<likes<<" Shares:"<<shares<<"\n";
    }
    const string& getID()const{
        return ID;
    }
    int getLikes()const{
        return likes;
    }
    int getShares()const{
        return shares;
    }
    void setID(const string &id){
        if(id.size()==0){
            cout<<"Invalid post ID\n";
            return;
        }
        ID=id;
    }
    void setLikes(int l){
        if(l<0){
            cout<<"Invalid likes\n";
            return;
        }
        likes=l;
    }
    void setShares(int s){
        if(s<0){
            cout<<"Invalid shares\n";
            return;
        }
        shares=s;
    }
    int viralScore()const{
        return (likes*1 + shares*3);
    }
    SocialPost& operator+=(int newLikes){
        if(newLikes<0){
            cout<<"Invalid like increment\n";
            return *this;
        }
        likes+=newLikes;
        return *this;
    }
    SocialPost& operator-=(int removedLikes){
        if(removedLikes<0){
            cout<<"Invalid like decrement\n";
            return *this;
        }
        likes=nonzero(likes-removedLikes);
        return *this;
    }
    bool operator==(const SocialPost &other)const{
        if((likes+shares)==(other.likes+other.shares)){
            return true;
        }
        else return false;
    }
    bool operator>(const SocialPost &other)const{
        if(viralScore()>other.viralScore()){
            return true;
        }
        else return false;
    }
    bool operator<(const SocialPost &other)const{
        if(viralScore()<other.viralScore()){
            return true;
        }
        else return false;
    }
    void display()const{
        cout<<"Post:"<<ID<<" Likes:"<<likes<<" Shares:"<<shares<<" ViralScore:"<<viralScore()<<"\n";
    }
};
int main(){
    SocialPost post1("POST101",100,20);
    SocialPost post2("POST102",80,30);
    post1+=50;
    post1.display();
    post1-=30;
    post1.display();
    if(post1>post2)
        cout<<"Post1 is trending\n";
    else
        cout<<"Post2 is trending\n";
    if(post1==post2)
        cout<<"Posts have equal popularity\n";
    else
        cout<<"Posts are not equal\n";
}


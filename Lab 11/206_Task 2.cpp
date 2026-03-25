#include <bits/stdc++.h>
using namespace std;
class IPlayer{
public:
    virtual void play()=0;
    virtual void pause()=0;
    virtual void stop()=0;
    virtual ~IPlayer()=default;
};
class IStreamable{
public:
    virtual void connectToInternet(string ssid)=0;
    virtual void disconnectInternet()=0;
    virtual ~IStreamable()=default;
};
class BasicPlayer:public IPlayer{
protected:
    string playerName;
public:
    BasicPlayer(string playerName="Unnamed"):playerName(playerName){}
    void play() override{
        cout<<"Basic Play\n";
    }
    void pause() override{
        cout<<"Basic Pause\n";
    }
    void stop() override{
        cout<<"Basic Stop\n";
    }
    void showName() const{
        cout<<"Player name: " << playerName << "\n";
    }
};
class SmartPlayer:public IPlayer,public IStreamable{
protected:
    string playerName;
    int volumeLevel;
public:
    SmartPlayer(string playerName="Unnamed",int volumeLevel=67):playerName(playerName),volumeLevel(volumeLevel){}
    void play() override{
        cout <<"Playing at "<<volumeLevel<<"%\n";
    }
    void pause() override{
        cout << "Paused\n";
    }
    void stop() override{
        cout << "Stopped\n";
    }
    void connectToInternet(string ssid) override{
        cout << "Connected to " << ssid << "\n";
    }
    void disconnectInternet() override{
        cout << "Disconnected from internet\n";
    }
    void adjustVolume(int level){
        volumeLevel = level;
        if(volumeLevel < 0) volumeLevel = 0;
        if(volumeLevel > 100) volumeLevel = 100;
    }
    void showVolume() const{
        cout << "Volume: " << volumeLevel << "%\n";
    }
};
class AdvancedDJ:public SmartPlayer{
    string djName;
public:
    AdvancedDJ(string playerName="Unnamed",string djName="DJ",int volumeLevel=67): SmartPlayer(playerName, volumeLevel),djName(djName) {}
    void play() override{
        SmartPlayer::play();
        cout << "DJ " << djName << " is mixing tracks.\n";
    }
    void mixTracks(){
        cout << "Mixing tracks...\n";
    }
    void setPlaylist(string playlistName){
        cout << "Playlist set to " << playlistName << ".\n";
    }
};
int main(){
    AdvancedDJ dj("ADJ","DJALOK");
    dj.connectToInternet("UNIWiFi");
    dj.play();
    dj.mixTracks();
    dj.setPlaylist("TheWeeknd");
    dj.pause();
    dj.adjustVolume(67);
    dj.showVolume();
    dj.stop();
    dj.disconnectInternet();
}

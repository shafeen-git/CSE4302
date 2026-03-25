#include <bits/stdc++.h>
using namespace std;
class DisplayUnit{
protected:
    float screenSize;
    string resolution;
public:
    DisplayUnit(float ssize=40.00,string res="4K"):screenSize(ssize),resolution(res){}
    void setScreenSize(float ssize) { screenSize = ssize; }
    void setResolution(string res) { resolution = res; }
    float getScreenSize() const{return screenSize;}
    string getResolution() const{return resolution;}
    void showVisuals(){
        cout <<"Displaying content at "<<resolution<<" on "<<screenSize<<" inches screen."<<"\n";
    }
    string getDisplayInfo(){
        return "Screen: "+to_string(screenSize)+" inches, Resolution: "+resolution;
    }
    virtual ~DisplayUnit(){
        cout <<"Display Unit turned off."<<"\n";
    }
};
class ComputingUnit{
protected:
    string processorModel;
    int ramSize;
public:
    ComputingUnit(string processor="I7",int ram=8):processorModel(processor),ramSize(ram){}
    void setProcessorModel(string processor){processorModel=processor;}
    void setRamSize(int ram){ramSize=ram;}
    string getProcessorModel()const{return processorModel;}
    int getRamSize()const{return ramSize;}
    void processStream(){
        cout <<"Decoding video stream using "<< processorModel <<" (" << ramSize <<" GB RAM)." <<"\n";
    }
    string getProcessingPower()const{
        if (ramSize < 4) return "Low";
        else if (ramSize==4) return "Medium";
        else return "High";
    }
    virtual ~ComputingUnit() {
        cout << "Computing Unit turned off." <<"\n";
    }
};
class Speaker{
private:
    int wattage;
    string position;
public:
    Speaker(int watts=10,string pos= "Left"):wattage(watts),position(pos){}
    void setWattage(int watts){wattage = watts;}
    void setPosition(string pos){position = pos;}
    int getWattage()const{ return wattage;}
    string getPosition()const{ return position;}
    void emitSound(){
        cout << "Boom! Sound coming from " << position << " speaker at " << wattage << " watts." <<"\n";
    }
    string getAudioConfig(){
        return position + " Speaker: " + to_string(wattage)+"W";
    }
    ~Speaker(){
        cout << position << " Speaker turned off." <<"\n";
    }
};
class MediaContent{
protected:
    string title;
    int duration;
    float fileSize;

public:
    MediaContent(string t = "Movie", int dur=0, float size=0.0):title(t),duration(dur),fileSize(size){}
    virtual void play()=0;
    string getContentInfo() {
        return "Title: "+title+ ",Duration: "+to_string(duration)+" min, File Size: " + to_string(fileSize) + " GB";
    }
    virtual string getMediaType()=0;
    string getTitle()const{ return title; }
    int getDuration()const{ return duration;}
    float getFileSize() { return fileSize; }
    virtual ~MediaContent() {}
};
class Movie:public MediaContent {
private:
    string director;
    bool hasHDR;
public:
    Movie(string t = "Movie",int dur=0,float size=0.0,string dir="Unknown",bool hdr=false): MediaContent(t, dur, size), director(dir), hasHDR(hdr) {}
    void play() override{
        cout <<"Playing movie: " << title << " directed by " << director << "." <<"\n";
    }

    string getMediaType() override {
        return "Movie";
    }
    string getDirector() { return director; }
    bool getHasHDR() { return hasHDR; }
};

class TVShow:public MediaContent {
private:
    int seasonNumber;
    int episodeNumber;
public:
    TVShow(string t = "Untitled Show", int dur = 0, float size = 0.0, int season = 1, int episode = 1)
        : MediaContent(t, dur, size), seasonNumber(season), episodeNumber(episode) {}

    void play() override {
        cout << "Playing TV Show: " << title << " (S" << seasonNumber << "E" << episodeNumber << ")." <<"\n";
    }
    string getMediaType()override{
        return "TV Show";
    }
    int getSeasonNumber(){return seasonNumber; }
    int getEpisodeNumber() { return episodeNumber; }
};
class SmartTV : public DisplayUnit, public ComputingUnit {
private:
    string brandName;
    Speaker speakers[2];
    MediaContent** contentLibrary;
    int contentCount;
    int contentCapacity;
public:
    SmartTV(float screenSize, string resolution, string processor, int ram,
            string brand, int speakerWattage, int capacity): DisplayUnit(screenSize, resolution),ComputingUnit(processor, ram),brandName(brand),contentCount(0),contentCapacity(capacity){
        speakers[0] = Speaker(speakerWattage, "Left");
        speakers[1] = Speaker(speakerWattage, "Right");
        contentLibrary = new MediaContent*[contentCapacity];
    }
    void watchContent(int contentIndex) {
        if (contentIndex < 0 || contentIndex >= contentCount) {
            cout << "Invalid content index!" <<"\n";
            return;
        }
        MediaContent* content = contentLibrary[contentIndex];
        cout << "\n--- Starting " << content->getMediaType() << " on " << brandName << " TV ---" <<"\n";
        content->play();
        showVisuals();
        processStream();
        for (int i = 0; i < 2; i++) {
            speakers[i].emitSound();
        }
    }
    void addToLibrary(MediaContent* newContent) {
        if (contentCount < contentCapacity) {
            contentLibrary[contentCount] = newContent;
            contentCount++;
            cout << "Added " << newContent->getMediaType() << " to library: " << newContent->getTitle() <<"\n";
        } else {
            cout << "Library is full!" << "\n";
        }
    }

    void browseLibrary() {
        cout << "\n=== " << brandName << " TV Library ===" <<"\n";
        if (contentCount == 0) {
            cout << "No content available." <<"\n";
            return;
        }
        for (int i = 0; i < contentCount; i++) {
            cout << "[" << i << "] " << contentLibrary[i]->getMediaType() << " - "<< contentLibrary[i]->getContentInfo() <<"\n";
        }
    }
    int getContentCount() {
        return contentCount;
    }
    string getBrandName() { return brandName; }
    ~SmartTV() {
        cout << brandName << " TV turned off." <<"\n";
    }
};

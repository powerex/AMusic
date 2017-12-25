//
// Created by azbest on 25.11.17.
//

#include "../header/MusicLibrary.h"

const vector<Performance *> &MusicLibrary::getPerformanceList() const {
    return performanceList;
}

void MusicLibrary::setPerformanceList(const vector<Performance *> &performanceList) {
    MusicLibrary::performanceList = performanceList;
}

const vector<Music *> &MusicLibrary::getMusicList() const {
    return musicList;
}

void MusicLibrary::setMusicList(const vector<Music *> &musicList) {
    MusicLibrary::musicList = musicList;
}

const vector<Quartet *> &MusicLibrary::getQuartetList() const {
    return quartetList;
}

void MusicLibrary::setQuartetList(const vector<Quartet *> &quartetList) {
    MusicLibrary::quartetList = quartetList;
}

MusicLibrary::MusicLibrary() {}



void MusicLibrary::addPerfofmance(Performance *p) {
    performanceList.push_back(p);
}

void MusicLibrary::addMusic(Music *m) {
    musicList.push_back(m);
}

void MusicLibrary::addQuartet(Quartet *q) {
    quartetList.push_back(q);
}

void MusicLibrary::save(bool binary) {
    if (binary) {
        fstream file;
        file.open("library.dat", ios::out | ios::in | ios::binary );

        file.write(reinterpret_cast<char*>(humanList.size()), sizeof(unsigned long));
        for (int i=0; i<humanList.size(); i++) {
            //file.write(reinterpret_cast<char*>(*humanList.at(i)), sizeof(Performer));
        }
        file.close();
    }
    else {

    }
}

const vector<Performer *> &MusicLibrary::getHumanList() const {
    return humanList;
}

void MusicLibrary::setHumanList(const vector<Performer *> &humanList) {
    MusicLibrary::humanList = humanList;
}

void MusicLibrary::addHuman(Performer *h) {
    humanList.push_back(h);
}

void MusicLibrary::printHumans() {
    Human::tableHead();
    for (Performer*& h: humanList){
        h->show();
    }
}

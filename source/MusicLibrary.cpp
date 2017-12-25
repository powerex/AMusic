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

        for (Human*& h: humanList){
            Human tmpH = *h;
            //file.write(reinterpret_cast<char*>(tmpH), sizeof(Human));
        }
        file.close();
    }
    else {

    }
}

const vector<Human *> &MusicLibrary::getHumanList() const {
    return humanList;
}

void MusicLibrary::setHumanList(const vector<Human *> &humanList) {
    MusicLibrary::humanList = humanList;
}

void MusicLibrary::addHuman(Human *h) {
    humanList.push_back(h);
}

void MusicLibrary::printHumans() {
    Human::tableHead();
    for (Human*& h: humanList){
        h->show();
    }
}

//
// Created by azbest on 25.11.17.
//

#include "../header/MusicLibrary.h"
#include "../header/UnknowReadData.h"

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
        ofstream file;
        file.open("library.dat", ios::trunc | ios::out | ios::in | ios::binary );

        unsigned long c = humanList.size();
        file.write(reinterpret_cast<char*>(&c), sizeof(unsigned long));

        for (Human*& h: humanList){
            if (typeid(*h).name() == typeid(Human).name()) {
                file.write("H",sizeof(char));
                h->write(&file);
            }
            else {
                file.write("P",sizeof(char));
                h->write(&file);
            }

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

void MusicLibrary::read(bool binary) {
    if (binary) {
        ifstream file;
        file.open("library.dat", ios::out | ios::in | ios::binary );
        file.seekg(0);

        unsigned long c = humanList.size();
        file.read(reinterpret_cast<char*>(&c), sizeof(unsigned long));

        Human** list = new Human*[c];

        for (auto i=0; i<c; i++) {
            char ch;
            file.read(&ch,sizeof(char));
            switch (ch) {
                case 'H': {
                    list[i] = new Human();
                    list[i]->read(&file);
                    this->humanList.push_back(list[i]);
                    break;
                }
                case 'P': {
                    list[i] = new Performer();
                    list[i]->read(&file);
                    this->humanList.push_back(list[i]);
                    break;
                }
                default: throw new UnknowReadData();
            }
        }
        file.close();
    }
    else {

    }
}

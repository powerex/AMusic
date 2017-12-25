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

void MusicLibrary::printQuartets() {
    Quartet::tableHead();
    for (Quartet*& q: quartetList){
        q->show();
    }
}

void MusicLibrary::save(bool binary) {
    if (binary) {
        ofstream file;
        file.open("library.dat", ios::trunc | ios::out | ios::in | ios::binary );

// Human save
        unsigned long c = humanList.size();

        file.write(reinterpret_cast<char*>(&c), sizeof(unsigned long));
        Human* h;
        for (auto i=0; i<c; i++) {
            h = getHumanById(i+1);
            if (typeid(*h).name() == typeid(Human).name()) {
                file.write("H",sizeof(char));
                h->write(&file);
            }
            else {
                file.write("P",sizeof(char));
                h->write(&file);
            }
        }
//Quartet save
        c = quartetList.size();
        file.write(reinterpret_cast<char*>(&c), sizeof(unsigned long));
        Quartet* q;
        for (auto j=0; j<c; j++) {
            q = getQuartetById(j+1);
            long id[4];
            for (auto i=0; i<4;i++) {
                id[i] = q->getQuartet()[i]->getId()-1;
                file.write(reinterpret_cast<char*>(&id[i]), sizeof(long));
            }
            long l = q->getId();
            file.write(reinterpret_cast<char*>(&l), sizeof(long));
        }
//Music save
        c = musicList.size();
        file.write(reinterpret_cast<char*>(&c), sizeof(unsigned long));
        Music* m;
        for (auto i=0; i<c; i++) {
            m = getMusicById(i+1);
            long tL = m->getId();
            file.write(reinterpret_cast<char*>(&tL), sizeof(long));
            int tOp = m->getOpus();
            file.write(reinterpret_cast<char*>(&tOp), sizeof(int));
            Date tD = m->getCreationDate();
            tD.write(&file);
            tL = m->getComposer()->getId()-1;
            file.write(reinterpret_cast<char*>(&tL), sizeof(long));
        }
//Performance write
        file.close();
    }
    else {

    }
}

void MusicLibrary::read(bool binary) {
    if (binary) {
        ifstream file;
        file.open("library.dat", ios::out | ios::in | ios::binary );
        file.seekg(0);

//Human read
        unsigned long c;
        file.read(reinterpret_cast<char*>(&c), sizeof(unsigned long));

        Human** hList = new Human*[c];
        for (auto i=0; i<c; i++) {
            char ch;
            file.read(&ch,sizeof(char));
            switch (ch) {
                case 'H': {
                    hList[i] = new Human();
                    hList[i]->read(&file);
                    this->humanList.push_back(hList[i]);
                    break;
                }
                case 'P': {
                    hList[i] = new Performer();
                    hList[i]->read(&file);
                    this->humanList.push_back(hList[i]);
                    break;
                }
                default: throw new UnknowReadData();
            }
        }
        Human::setHumanCount(c);
//Quartet read
        file.read(reinterpret_cast<char*>(&c), sizeof(unsigned long));
        Quartet** qList = new Quartet*[c];
        for (auto i=0; i<c; i++) {
            long id[4];
            for (auto j=0; j<4; j++) {
                file.read(reinterpret_cast<char*>(&id[j]), sizeof(long));
            }
            qList[i] = new Quartet(
                    (Performer *) this->getHumanList().at(id[0]),
                    (Performer *) this->getHumanList().at(id[1]),
                    (Performer *) this->getHumanList().at(id[2]),
                    (Performer *) this->getHumanList().at(id[3])
            );
            long l;
            file.read(reinterpret_cast<char*>(&l), sizeof(long));
            qList[i]->setId(l);
            this->addQuartet(qList[i]);
        }
        Quartet::setQuartetCount(c);
//Music read
        file.read(reinterpret_cast<char*>(&c), sizeof(unsigned long));
        Music** mList = new Music*();

        for (auto i=0; i<c; i++) {
            long tId;
            file.read(reinterpret_cast<char*>(&tId), sizeof(long));
            int tOpus;
            file.read(reinterpret_cast<char*>(&tOpus), sizeof(int));
            Date tD;
            tD.read(&file);
            long tComposerId;
            file.read(reinterpret_cast<char*>(&tComposerId), sizeof(long));
            mList[i] = new Music(humanList.at(tComposerId), tOpus, tD);
            mList[i]->setId(tId);
            this->addMusic(mList[i]);
        }
        Music::setMusicCount(c);
        file.close();
    }
    else {

    }
}

Human *MusicLibrary::getHumanById(long id) {
    if (id < 1 || id > this->humanList.size())
        throw new IndexOfBoundException();
    for (Human*& h: humanList) {
        if (h->getId() == id) {
            return h;
        }
    }
    return nullptr;
}

Human *MusicLibrary::getPerformanceById(long id) {
    return nullptr;
}

Music *MusicLibrary::getMusicById(long id) {
    if (id < 1 || id > this->musicList.size())
        throw new IndexOfBoundException();
    for (Music*& m: musicList) {
        if (m->getId() == id) {
            return m;
        }
    }
    return nullptr;
}

Quartet  *MusicLibrary::getQuartetById(long id) {
    if (id < 1 || id > this->quartetList.size())
        throw new IndexOfBoundException();
    for (Quartet*& q: quartetList) {
        if (q->getId() == id) {
            return q;
        }
    }
    return nullptr;
}

void MusicLibrary::printMusics() {
    Music::tableHead();
    for (Music*& m: musicList){
        m->show();
    }
}

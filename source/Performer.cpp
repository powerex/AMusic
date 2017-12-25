#include "../header/Performer.h"

void Performer::setMusic(Musician::musician music) {
    this->music.insert(music);
}

Performer::Performer(const string &name, const string &surname, const Date &birthday, Musician::musician music) : Human(
        name, surname, birthday) {
    this->music.insert(music);
}

Performer::Performer() {}

bool Performer::isPerform(Musician::musician music) {
    return this->music.find(music) != this->music.end();
}

Performer::Performer(Human human) {

}

void Performer::read(ifstream *in) {
    Human::read(in);
    unsigned long c;
    in->read(reinterpret_cast<char*>(&c), sizeof(unsigned long));
    for (auto i=0; i<c; ++i) {
        Musician::musician tM;
        in->read(reinterpret_cast<char*>(&tM), sizeof(Musician::musician));
        this->setMusic(tM);
    }

}

void Performer::write(ofstream *out) {
    Human::write(out);
    unsigned long c = music.size();
    out->write(reinterpret_cast<char*>(&c), sizeof(unsigned long));
    for (const Musician::musician & m: music) {
        Musician::musician mm = m;
        out->write(reinterpret_cast<char*>(&mm), sizeof(Musician::musician));
    }

}

const set<Musician::musician> &Performer::getMusic() const {
    return music;
}

#include "../header/Performer.h"


Musician::musician Performer::getMusic() const {
    return music;
}

void Performer::setMusic(Musician::musician music) {
    Performer::music = music;
}

Performer::Performer(const string &name, const string &surname, const Date &birthday, Musician::musician music) : Human(
        name, surname, birthday), music(music) {}

Performer::Performer() {}

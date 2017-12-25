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

#ifndef AMUSIC_PERFORMER_H
#define AMUSIC_PERFORMER_H

#include "Human.h"
#include "Musician.h"

#include <set>

class Performer: public Human {
private:
    set<Musician::musician> music;
public:

    Performer();

    Performer(const string &name, const string &surname, const Date &birthday, Musician::musician music);

    void setMusic(Musician::musician music);

    bool isPerform(Musician::musician music);

    Performer(Human human);
};


#endif //AMUSIC_PERFORMER_H

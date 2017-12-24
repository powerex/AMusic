#ifndef AMUSIC_PERFORMER_H
#define AMUSIC_PERFORMER_H

#include "Human.h"
#include "Musician.h"

class Performer: public Human {
private:
    Musician::musician music;
public:
    Musician::musician getMusic() const;

    Performer();

    Performer(const string &name, const string &surname, const Date &birthday, Musician::musician music);

    void setMusic(Musician::musician music);
};


#endif //AMUSIC_PERFORMER_H

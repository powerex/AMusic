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

    const set<Musician::musician> &getMusic() const;

    bool isPerform(Musician::musician music);

    explicit Performer(Human human);

    void read(ifstream *in);

    void write(ofstream *out);
};


#endif //AMUSIC_PERFORMER_H

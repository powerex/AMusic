#ifndef AMUSIC_MUSIC_H
#define AMUSIC_MUSIC_H


#include "Human.h"

class Music {
private:
    Human* composer;
    int opus;
    Date creationDate;
public:
    Human *getComposer() const;

    void setComposer(Human *composer);

    int getOpus() const;

    void setOpus(int opus);

    const Date &getCreationDate() const;

    void setCreationDate(const Date &creationDate);
};


#endif //AMUSIC_MUSIC_H

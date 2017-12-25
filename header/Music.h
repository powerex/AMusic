#ifndef AMUSIC_MUSIC_H
#define AMUSIC_MUSIC_H


#include "Human.h"

class Music {
private:
    long id;
    Human* composer;
    int opus;
    Date creationDate;
protected:
    static long musicCount;
public:
    static void setMusicCount(long musicCount);

    Music();

    Music(Human *composer, int opus, const Date &creationDate);

    Human *getComposer() const;

    long getId() const;

    void setId(long id);

    void setComposer(Human *composer);

    int getOpus() const;

    void setOpus(int opus);

    const Date &getCreationDate() const;

    void setCreationDate(const Date &creationDate);

    static void tableHead();

    void show();
};


#endif //AMUSIC_MUSIC_H

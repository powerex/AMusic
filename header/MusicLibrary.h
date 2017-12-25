#ifndef AMUSIC_MUSICLIBRARY_H
#define AMUSIC_MUSICLIBRARY_H


#include <vector>
#include <fstream>
#include <typeinfo>

#include "Performance.h"
#include "Performer.h"
#include "Music.h"

class MusicLibrary {
private:
    vector<Human*> humanList;
    vector<Performance*> performanceList;
    vector<Music*> musicList;
    vector<Quartet*> quartetList;
public:

    MusicLibrary();

    const vector<Human *> &getHumanList() const;

    void setHumanList(const vector<Human *> &humanList);

    const vector<Performance *> &getPerformanceList() const;

    void setPerformanceList(const vector<Performance *> &performanceList);

    const vector<Music *> &getMusicList() const;

    void setMusicList(const vector<Music *> &musicList);

    const vector<Quartet *> &getQuartetList() const;

    void setQuartetList(const vector<Quartet *> &quartetList);

    void addHuman(Human* h);

    void addPerfofmance(Performance* p);

    void addMusic(Music* m);

    void addQuartet(Quartet* q);

    void save(bool binary = true);

    void read(bool binary = true);

    void printHumans();

    void printQuartets();

    void printMusics();

    Human* getHumanById(long id);
    Human* getPerformanceById(long id);
    Music* getMusicById(long id);
    Quartet* getQuartetById(long id);
};


#endif //AMUSIC_MUSICLIBRARY_H

#ifndef AMUSIC_MUSICLIBRARY_H
#define AMUSIC_MUSICLIBRARY_H


#include <vector>
#include <fstream>

#include "Performance.h"
#include "Music.h"

class MusicLibrary {
private:
    vector<Performer*> humanList;
    vector<Performance*> performanceList;
    vector<Music*> musicList;
    vector<Quartet*> quartetList;
public:

    MusicLibrary();

    const vector<Performer *> &getHumanList() const;

    void setHumanList(const vector<Performer *> &humanList);

    const vector<Performance *> &getPerformanceList() const;

    void setPerformanceList(const vector<Performance *> &performanceList);

    const vector<Music *> &getMusicList() const;

    void setMusicList(const vector<Music *> &musicList);

    const vector<Quartet *> &getQuartetList() const;

    void setQuartetList(const vector<Quartet *> &quartetList);

    void addHuman(Performer* h);

    void addPerfofmance(Performance* p);

    void addMusic(Music* m);

    void addQuartet(Quartet* q);

    void save(bool binary = true);

    void printHumans();
};


#endif //AMUSIC_MUSICLIBRARY_H

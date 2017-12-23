#ifndef AMUSIC_MUSICLIBRARY_H
#define AMUSIC_MUSICLIBRARY_H


#include <vector>
#include "Performance.h"
#include "Music.h"

class MusicLibrary {
private:
    vector<Performance*> performanceList;
    vector<Music*> musicList;
    vector<Quartet*> quartetList;
public:
    const vector<Performance *> &getPerformanceList() const;

    void setPerformanceList(const vector<Performance *> &performanceList);

    const vector<Music *> &getMusicList() const;

    void setMusicList(const vector<Music *> &musicList);

    const vector<Quartet *> &getQuartetList() const;

    void setQuartetList(const vector<Quartet *> &quartetList);
};


#endif //AMUSIC_MUSICLIBRARY_H

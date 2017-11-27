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
};


#endif //AMUSIC_MUSICLIBRARY_H

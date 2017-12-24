//
// Created by azbest on 25.11.17.
//

#include "../header/MusicLibrary.h"

const vector<Performance *> &MusicLibrary::getPerformanceList() const {
    return performanceList;
}

void MusicLibrary::setPerformanceList(const vector<Performance *> &performanceList) {
    MusicLibrary::performanceList = performanceList;
}

const vector<Music *> &MusicLibrary::getMusicList() const {
    return musicList;
}

void MusicLibrary::setMusicList(const vector<Music *> &musicList) {
    MusicLibrary::musicList = musicList;
}

const vector<Quartet *> &MusicLibrary::getQuartetList() const {
    return quartetList;
}

void MusicLibrary::setQuartetList(const vector<Quartet *> &quartetList) {
    MusicLibrary::quartetList = quartetList;
}

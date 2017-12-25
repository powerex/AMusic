//
// Created by azbest on 25.11.17.
//

#include "../header/Music.h"

Human *Music::getComposer() const {
    return composer;
}

void Music::setComposer(Human *composer) {
    Music::composer = composer;
}

int Music::getOpus() const {
    return opus;
}

void Music::setOpus(int opus) {
    Music::opus = opus;
}

const Date &Music::getCreationDate() const {
    return creationDate;
}

void Music::setCreationDate(const Date &creationDate) {
    Music::creationDate = creationDate;
}

long Music::getId() const {
    return id;
}

void Music::setId(long id) {
    Music::id = id;
}

void Music::show() {
    cout << "|" << setw(18) << opus << " |"
         << setw(18) << (*composer).getName() << " | "
         << setw(13) << creationDate << " |" << setfill(' ')
         << setw(10) << id << " |\n";
}

void Music::tableHead() {
    cout << "============================== MUSIC =============================\n";
    cout << "|" << setw(20) << "  Opus |"
         << setw(20) << "  Composer |"
         << setw(13) << "  Date |"
         << setw(13) << "  id |\n";
    cout << "==================================================================\n";
}

Music::Music(Human *composer, int opus, const Date &creationDate) : composer(composer), opus(opus),
                                                                    creationDate(creationDate) {
    id = ++Music::musicCount;
}

void Music::setMusicCount(long musicCount) {
    Music::musicCount = musicCount;
}

Music::Music() {}

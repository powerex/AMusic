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

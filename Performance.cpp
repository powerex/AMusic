//
// Created by azbest on 25.11.17.
//

#include "Performance.h"

Music *Performance::getMucis() const {
    return mucis;
}

void Performance::setMucis(Music *mucis) {
    Performance::mucis = mucis;
}

Quartet *Performance::getQuartet() const {
    return quartet;
}

void Performance::setQuartet(Quartet *quartet) {
    Performance::quartet = quartet;
}

const Date &Performance::getDate() const {
    return date;
}

void Performance::setDate(const Date &date) {
    Performance::date = date;
}

long Performance::getDuration() const {
    return duration;
}

void Performance::setDuration(long duration) {
    Performance::duration = duration;
}

Performance::operator long int() const {
    return 0;
}

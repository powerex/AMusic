//
// Created by azbest on 25.11.17.
//

#ifndef AMUSIC_PERFORMANCE_H
#define AMUSIC_PERFORMANCE_H


#include "Performer.h"
#include "Quartet.h"

class Performance {
private:
    Performer* performer;
    Quartet* quartet;
    Date date;
    long duration;
};


#endif //AMUSIC_PERFORMANCE_H

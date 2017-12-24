//
// Created by azbest on 25.11.17.
//

#ifndef AMUSIC_PERFORMANCE_H
#define AMUSIC_PERFORMANCE_H


#include "Performer.h"
#include "Quartet.h"
#include "Music.h"

class Performance {
private:
    Music* mucis;
    Quartet* quartet;
    Date date;
    long duration;
public:
    Music *getMucis() const;

    void setMucis(Music *mucis);

    Quartet *getQuartet() const;

    void setQuartet(Quartet *quartet);

    const Date &getDate() const;

    void setDate(const Date &date);

    long getDuration() const;

    void setDuration(long duration);

    operator long int() const;
};


#endif //AMUSIC_PERFORMANCE_H

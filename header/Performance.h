//
// Created by azbest on 25.11.17.
//

#ifndef AMUSIC_PERFORMANCE_H
#define AMUSIC_PERFORMANCE_H


#include "Performer.h"
#include "Quartet.h"
#include "Music.h"

#include <iostream>
#include <iomanip>

class Performance {
private:
    long id;
    Music* mucis;
    Quartet* quartet;
    Date date;
    long duration;
protected:
    static long performanceCount;
public:
    Performance(Music *mucis, Quartet *quartet, const Date &date, long duration);

    Music *getMucis() const;

    void setMucis(Music *mucis);

    Quartet *getQuartet() const;

    long getId() const;

    void setId(long id);

    static long getPerformanceCount();

    static void setPerformanceCount(long performanceCount);

    void setQuartet(Quartet *quartet);

    const Date &getDate() const;

    void setDate(const Date &date);

    long getDuration() const;

    void setDuration(long duration);

    explicit operator long int() const;

    static void tableHead();

    void show();
};


#endif //AMUSIC_PERFORMANCE_H

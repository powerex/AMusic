//
// Created by azbest on 23.11.17.
//

#ifndef AMUSIC_DATE_H
#define AMUSIC_DATE_H

#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
    short day;
    short month;
    int year;
public:
    Date(short day, short month, int year);

    Date();

    short getDay() const;

    void setDay(short day);

    short getMonth() const;

    void setMonth(short month);

    int getYear() const;

    void setYear(int year);

    friend ostream& operator<<(ostream& os, const Date& dt);
};


#endif //AMUSIC_DATE_H

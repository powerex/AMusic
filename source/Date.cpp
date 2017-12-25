//
// Created by azbest on 23.11.17.
//

#include "../header/Date.h"

short Date::getDay() const {
    return day;
}

void Date::setDay(short day) {
    if (day > 0 && day < 32)
        Date::day = day;
}

short Date::getMonth() const {
    return month;
}

void Date::setMonth(short month) {
    if (month > 0 && month < 13)
        Date::month = month;
}

int Date::getYear() const {
    if (year > 0)
        return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

Date::Date(short day, short month, int year) : day(day), month(month), year(year) {}

Date::Date() {}

ostream &operator<<(ostream &os, const Date &dt) {
    os << setfill('0') << setw(2) << dt.day << '/' << setw(2) << dt.month << '/' << setw(4) << dt.year;
    return os;
}

void Date::read(ifstream *in) {
    in->read((char*)this, sizeof(Date));
}

void Date::write(ofstream *out) {
    out->write(reinterpret_cast<char*>(this), sizeof(Date));
}
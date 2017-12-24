//
// Created by azbest on 23.11.17.
//

#include "../header/Date.h"

short Date::getDay() const {
    return day;
}

void Date::setDay(short day) {
    Date::day = day;
}

short Date::getMonth() const {
    return month;
}

void Date::setMonth(short month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

Date::Date(short day, short month, int year) : day(day), month(month), year(year) {}

Date::Date() {}
//
// Created by azbest on 23.11.17.
//

#ifndef AMUSIC_HUMAN_H
#define AMUSIC_HUMAN_H

#include <iostream>
#include "Date.h"

using namespace std;

class Human {
protected:
    string name;
    string surname;
    Date birthday;
public:
    Human(const string &name, const string &surname, const Date &birthday);

    Human();

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    const Date &getBirthday() const;

    void setBirthday(const Date &birthday);
};


#endif //AMUSIC_HUMAN_H

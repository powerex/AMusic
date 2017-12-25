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
    static long humanCount;
protected:
    long id;
    string name;
    string surname;
    Date birthday;
public:

    static void setHumanCount(long humanCount);

    Human(const string &name, const string &surname, const Date &birthday);

    Human();

    long getId() const;

    void setId(long id);

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    const Date &getBirthday() const;

    void setBirthday(const Date &birthday);

    static void tableHead();

    void show();

    virtual void read(ifstream *in);

    virtual void write(ofstream *out);
};


#endif //AMUSIC_HUMAN_H

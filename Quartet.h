//
// Created by azbest on 25.11.17.
//

#ifndef AMUSIC_QUARTET_H
#define AMUSIC_QUARTET_H

#include "Performer.h"
#include "IndexOfBoundException.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Quartet {
private:
    Performer** quartet;
public:
    Performer **getQuartet() const;

    Quartet(Performer* firstCellist, Performer* secondCellist, Performer* altist, Performer* violonist);

    void setQuartet(Performer **quartet);

    Performer* operator[](int no);

    virtual ~Quartet();

    static void tableHead();

    void show();

};


#endif //AMUSIC_QUARTET_H

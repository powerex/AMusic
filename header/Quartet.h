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
    long id;
protected:
    static long quartetCount;
public:
    Performer **getQuartet() const;

    static void setQuartetCount(long quartetCount);

    Quartet();

    Quartet(Performer* firstCellist, Performer* secondCellist, Performer* altist, Performer* violonist);

    void setQuartet(Performer **quartet);

    Performer* operator[](int no);

    virtual ~Quartet();

    static void tableHead();

    void show();

    long getId() const;

    void setId(long id);

    void read(ifstream *in);

    void write(ofstream *out);

};


#endif //AMUSIC_QUARTET_H

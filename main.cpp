#include <iostream>

#include "header/Quartet.h"
#include "header/Human.h";
#include "header/Generator.h"


int main() {

    Performer p1(Generator::getInstance().getWord(),
                 Generator::getInstance().getWord(),
                 Generator::getInstance().getDate(),
                    Musician::cellist);

    Performer p2(Generator::getInstance().getWord(),
                 Generator::getInstance().getWord(),
                 Generator::getInstance().getDate(),
                 Musician::cellist);

    Performer p3(Generator::getInstance().getWord(),
                 Generator::getInstance().getWord(),
                 Generator::getInstance().getDate(),
                 Musician::altist);

    Performer p4(Generator::getInstance().getWord(),
                 Generator::getInstance().getWord(),
                 Generator::getInstance().getDate(),
                 Musician::violinist);

    Performer t1(Generator::getInstance().getWord(),
                 Generator::getInstance().getWord(),
                 Generator::getInstance().getDate(),
                 Musician::cellist);

    Performer t2(Generator::getInstance().getWord(),
                 Generator::getInstance().getWord(),
                 Generator::getInstance().getDate(),
                 Musician::cellist);

    Performer t3(Generator::getInstance().getWord(),
                 Generator::getInstance().getWord(),
                 Generator::getInstance().getDate(),
                 Musician::altist);

    Performer t4(Generator::getInstance().getWord(),
                 Generator::getInstance().getWord(),
                 Generator::getInstance().getDate(),
                 Musician::violinist);



    Quartet q1(&p1, &p2, &p3, &p4);
    Quartet q2(&t1, &p1, &t3, &t4);

    Quartet::tableHead();
    q1.show();
    q2.show();
    return 0;
}
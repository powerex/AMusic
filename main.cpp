#include <iostream>
#include <typeinfo>

#include "header/Quartet.h"
#include "header/Music.h"
#include "header/Human.h";
#include "header/Performer.h"
#include "header/Generator.h"
#include "header/Performance.h"
#include "header/MusicLibrary.h"

long Human::humanCount = 0;
long Music::musicCount = 0;
long Performance::performanceCount = 0;

int main() {

    Human h1(Generator::getInstance().getWord(),
             Generator::getInstance().getWord(),
             Generator::getInstance().getDate());

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

    Music m1(&h1,
             Generator::getInstance().getInt(1, 100),
             Generator::getInstance().getDate());

    Music m2(&p1,
             Generator::getInstance().getInt(1, 100),
             Generator::getInstance().getDate());

    Quartet q1(&p1, &p2, &p3, &p4);
    Quartet q2(&t1, &p1, &t3, &t4);

    Performance pr1(&m1, &q1, Generator::getInstance().getDate(), Generator::getInstance().getInt(5, 20));
    Performance pr2(&m2, &q2, Generator::getInstance().getDate(), Generator::getInstance().getInt(5, 20));

    MusicLibrary library;

    library.addHuman(&h1);
    library.addHuman(&p4);
    library.addHuman(&p3);
    library.addHuman(&p2);
    library.addHuman(&p1);
    library.addHuman(&t1);
    library.addHuman(&t2);
    library.addHuman(&t3);
    library.addHuman(&t4);


    Quartet::tableHead();
    q1.show();
    q2.show();

    cout << "\n\n";
    library.printHumans();

    cout << "\n\n";
    Music::tableHead();
    m1.show();
    m2.show();

    cout << "\n\n";
    Performance::tableHead();
    pr1.show();
    pr2.show();

/*
    ofstream out;
    out.open("test.dat", ios::trunc | ios::out | ios::binary );
    h1.write(&out);
    p1.write(&out);
    p3.write(&out);
    out.close();

    ifstream in;
    in.open("test.dat", ios::in | ios::binary);
    in.seekg(0);
    Human hh;
    hh.read(&in);
    Performer pp;
    pp.read(&in);
    Performer tt;
    tt.read(&in);
    in.close();

    hh.show();
    pp.show();
    tt.show();

    if (pp.isPerform(Musician::cellist)) cout << "Cellist\n";
    if (pp.isPerform(Musician::altist)) cout << "Altist\n";
    if (pp.isPerform(Musician::violinist)) cout << "Violonist\n";

    cout << "\n\n";
    if (tt.isPerform(Musician::cellist)) cout << "Cellist\n";
    if (tt.isPerform(Musician::altist)) cout << "Altist\n";
    if (tt.isPerform(Musician::violinist)) cout << "Violonist\n";
//*/

    library.save();

    MusicLibrary ml;
    ml.read();
    ml.printHumans();

    return 0;
}
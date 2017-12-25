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
long Quartet::quartetCount = 0;
long Performance::performanceCount = 0;

long Performance::getId() const {
    return id;
}

void Performance::setId(long id) {
    Performance::id = id;
}

void Performance::setPerformanceCount(long performanceCount) {
    Performance::performanceCount = performanceCount;
}

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

    Music m3(&p1,
             Generator::getInstance().getInt(1, 100),
             Generator::getInstance().getDate());

    Quartet q1(&p1, &p2, &p3, &p4);
    Quartet q2(&t1, &p1, &t3, &t4);

    Performance pr1(&m1, &q1, Generator::getInstance().getDate(), Generator::getInstance().getInt(5, 20));
    Performance pr2(&m2, &q2, Generator::getInstance().getDate(), Generator::getInstance().getInt(5, 20));
    Performance pr3(&m1, &q2, Generator::getInstance().getDate(), Generator::getInstance().getInt(5, 20));
    Performance pr4(&m1, &q2, Generator::getInstance().getDate(), Generator::getInstance().getInt(5, 20));
    Performance pr5(&m2, &q2, Generator::getInstance().getDate(), Generator::getInstance().getInt(5, 20));

    MusicLibrary library;

    library.addHuman(&h1);
    library.addHuman(&p2);
    library.addHuman(&p1);
    library.addHuman(&p3);
    library.addHuman(&p4);
    library.addHuman(&t1);
    library.addHuman(&t2);
    library.addHuman(&t3);
    library.addHuman(&t4);


    library.addQuartet(&q2);
    library.addQuartet(&q1);

    library.addMusic(&m1);
    library.addMusic(&m2);
    library.addMusic(&m3);

    library.addPerfofmance(&pr2);
    library.addPerfofmance(&pr1);
    library.addPerfofmance(&pr3);
    library.addPerfofmance(&pr4);
    library.addPerfofmance(&pr5);

    cout << "\n\n";
    library.printHumans();

    cout << "\n\n";
    library.printQuartets();

    cout << "\n\n";
    library.printMusics();

    cout << "\n\n";
    library.printPerformances();

    library.save();

    cout << "\n\n\n AFTER READING \n\n";

    MusicLibrary ml;
    ml.read();

    cout << "\n\n";
    ml.printHumans();

    cout << "\n\n";
    ml.printQuartets();

    cout << "\n\n";
    ml.printMusics();

    cout << "\n\n";
    ml.printPerformances();

    cout << "\n" << "Average count: " << ml.averageCount() << "\n";

    library.save("textinfo", false);

    return 0;
}
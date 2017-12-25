//
// Created by azbest on 25.11.17.
//

#include "../header/Quartet.h"

Performer **Quartet::getQuartet() const {
    return quartet;
}

void Quartet::setQuartet(Performer **quartet) {
    Quartet::quartet = quartet;
}

Quartet::Quartet(Performer *firstCellist, Performer *secondCellist, Performer *altist, Performer *violonist) {
    quartet = new Performer*[4];
    for (int i=0;i<4;i++)
        quartet[i] = new Performer();
    quartet[0] = firstCellist;
    quartet[1] = secondCellist;
    quartet[2] = altist;
    quartet[3] = violonist;
    id = ++Quartet::quartetCount;
}

Quartet::~Quartet() {
    delete [] quartet;
}

Performer *Quartet::operator[](int no) {
    if (no < 1 || no > 4)
        throw new IndexOfBoundException();
    return quartet[no-1];
}

void Quartet::tableHead() {
    cout << "\n======================================= QUARTET ==========================================\n";
    cout << "|" << setw(20) << "  First Cellist |"
         << setw(20) << "  Second Cellist |"
         << setw(20) << "  Altist |"
         << setw(20) << "  Violonist |"
         << setw(10) << " ID |\n";
    cout << "==========================================================================================\n";

}

void Quartet::show() {
    cout << "|" << setw(18) << quartet[0]->getName() << " |"
         << setw(18) << quartet[1]->getName() << " |"
         << setw(18) << quartet[2]->getName() << " |"
         << setw(18) << quartet[3]->getName() << " |"
         << setw(7) << id << " |\n";
}

Quartet::Quartet() {}

long Quartet::getId() const {
    return id;
}

void Quartet::setId(long id) {
    Quartet::id = id;
}

void Quartet::setQuartetCount(long quartetCount) {
    Quartet::quartetCount = quartetCount;
}

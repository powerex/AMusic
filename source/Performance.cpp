//
// Created by azbest on 25.11.17.
//

#include "../header/Performance.h"

Music *Performance::getMucis() const {
    return mucis;
}

void Performance::setMucis(Music *mucis) {
    Performance::mucis = mucis;
}

Quartet *Performance::getQuartet() const {
    return quartet;
}

void Performance::setQuartet(Quartet *quartet) {
    Performance::quartet = quartet;
}

const Date &Performance::getDate() const {
    return date;
}

void Performance::setDate(const Date &date) {
    Performance::date = date;
}

long Performance::getDuration() const {
    return duration;
}

void Performance::setDuration(long duration) {
    Performance::duration = duration;
}

Performance::operator long int() const {
    return duration;
}

void Performance::show() {
    cout << "|" << setw(18) << (*mucis).getOpus() << " |"
         << setw(18) << ((*quartet).getQuartet()[0])->getName() << " | "
         << setw(13) << date << " |" << setfill(' ')
         << setw(10) << duration << " |"
         << setw(7) << id << " |\n";
    cout << "|" << setw(18) << (*mucis).getComposer()->getName() << " |"
         << setw(18) << ((*quartet).getQuartet()[1])->getName() << " |"
         << setw(12) << "" << "|"
         << setw(10) << "" << " |"
         << setw(7) << "" << " |\n";
    cout << "|" << setw(8) << "" << (*mucis).getCreationDate() << " |" << setfill(' ')
         << setw(18) << ((*quartet).getQuartet()[2])->getName() << " |"
         << setw(12) << "" << "|"
         << setw(10) << "" << " |"
         << setw(7) << "" << " |\n";
    cout << "|" << setw(20) << " |"
         << setw(18) << ((*quartet).getQuartet()[3])->getName() << " |"
         << setw(12) << "" << "|"
         << setw(10) << "" << " |"
         << setw(7) << "" << " |\n";
    cout << "|-------------------+-------------------+------------+-----------+--------|\n";
}

void Performance::tableHead() {
    cout << "=================================== PERFORMANCE ===========================\n";
    cout << "|" << setw(20) << "  Music |"
         << setw(20) << "  Quartet |"
         << setw(13) << "  Date |"
         << setw(10) << "  Duration |"
         << setw(10) << " id |\n";
    cout << "===========================================================================\n";
}

Performance::Performance(Music *mucis, Quartet *quartet, const Date &date, long duration) : mucis(mucis),
                                                                                            quartet(quartet),
                                                                                            date(date),
                                                                                            duration(duration) {
    id = ++Performance::performanceCount;
}

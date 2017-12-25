//
// Created by azbest on 23.11.17.
//

#include "../header/Human.h"

const string &Human::getName() const {
    return name;
}

void Human::setName(const string &name) {
    Human::name = name;
}

const string &Human::getSurname() const {
    return surname;
}

void Human::setSurname(const string &surname) {
    Human::surname = surname;
}

const Date &Human::getBirthday() const {
    return birthday;
}

void Human::setBirthday(const Date &birthday) {
    Human::birthday = birthday;
}

Human::Human(const string &name, const string &surname, const Date &birthday) : name(name), surname(surname),
                                                                                birthday(birthday) {
    this->id = ++Human::humanCount;
}

Human::Human() {}

long Human::getId() const {
    return id;
}

void Human::setId(long id) {
    Human::id = id;
}

void Human::show() {
    cout << "|" << setw(18) << name << " |"
         << setw(18) << surname << " | "
         << setw(13) << birthday << " |" << setfill(' ')
         << setw(7) << id << " |\n";
}

void Human::tableHead() {
    cout << "============================= HUMAN ===========================\n";
    cout << "|" << setw(20) << "  Name |"
         << setw(20) << "  Surname |"
         << setw(13) << "  Date |"
         << setw(10) << "  id |\n";
    cout << "===============================================================\n";
}

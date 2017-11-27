//
// Created by azbest on 23.11.17.
//

#include "Human.h"

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
                                                                                birthday(birthday) {}

Human::Human() {}

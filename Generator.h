//
// Created by azbest on 15.12.17.
//

#ifndef LAB678_NAMEGENERATOR_H
#define LAB678_NAMEGENERATOR_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Date.h"

using namespace std;

class Generator {
private:
    Generator();
    Generator(Generator const&);
    void operator=(Generator const&); // Don't implement
public:
    static Generator& getInstance();
    string getWord();
    Date getDate();
};


#endif //LAB678_NAMEGENERATOR_H

#ifndef READANDWRITE_H
#define READANDWRITE_H
#include <iostream>
#include "dsstring.h"

struct readandWrite {
    //default constructor
    readandWrite();

    //reads in input file from argv[1]
    void readInput(dsString*&, char*, int&, int&);
    //wirtes out to output file to argv[2]
    void writeOutput(dsString*&, char*, int&);
    ~readandWrite();
};

#endif // READANDWRITE_H

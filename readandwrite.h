#ifndef READANDWRITE_H
#define READANDWRITE_H
#include <iostream>
#include "dsvector.h"
#include "dsstring.h"

struct readandWrite {
    //default constructor
    readandWrite();

    //reads in input file from argv[1]
    void readInput(dsVector<dsString>&, char*, int&);
    void readInput(dsString*&, char*, int&);
    //wirtes out to output file to argv[2]
    void writeOutput(dsVector<dsString>&, char*, int&);
    ~readandWrite();
};

#endif // READANDWRITE_H

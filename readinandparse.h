#ifndef READINANDPARSE_H
#define READINANDPARSE_H
#include <iostream>
#include "dsvector.h"
#include "dsstring.h"

class readInAndParse
{
private:

//    //private vector of Word class
//    dsVector<dsString> indexOfWords;
//    int lineCount;

public:

    //default constructor
    readInAndParse();

    //reads input from argvs
    void readInput(dsVector<dsString>&, char*);
    ~readInAndParse();


};

#endif // READINANDPARSE_H

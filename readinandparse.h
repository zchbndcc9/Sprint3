#ifndef READINANDPARSE_H
#define READINANDPARSE_H
#include <iostream>
#include "dsvector.h"
#include "dsstring.h"
class readInAndParse
{
private:

    //private vector of Word class
    dsVector<dsString> indexOfWords;
    int lineCount;

public:

    //default constructor
    readInAndParse();

    //reads input from argvs
    void readInput(char* input_file, char* outpath);
    ~readInAndParse();


};

#endif // READINANDPARSE_H

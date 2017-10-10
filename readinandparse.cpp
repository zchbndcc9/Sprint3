#include "readinandparse.h"
#include <fstream>
#include <iostream>
#include <cstring>

readInAndParse::readInAndParse() {
//default
}

//reads in dictionary file from argv[1]
void readInAndParse::readInput(dsVector<dsString>& vec, char* input_file, int& wordsToPrint){

    ifstream inFile(input_file);

    //checks if dictFile isnt opening
    if (!inFile)
        cout <<"Houston we have a problem!!!!!!!!!!!" << endl;

    //can use index[0].w to call the variable or whatever in getPageNums

    dsString line;
    int totalWords;

    inFile >> totalWords;
    inFile >> wordsToPrint;

    char buffer[80] ={0};

    //while the file isnt at the end
    while(!inFile.eof()){
        inFile >> buffer;
        line = buffer;
        vec.push_back(line);
    }

    inFile.close();
}

readInAndParse::~readInAndParse(){

}


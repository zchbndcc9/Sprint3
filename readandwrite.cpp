#include "readandwrite.h"
#include <fstream>
#include <iostream>

readandWrite::readandWrite(){

}

void readandWrite::readInput(dsVector<dsString>& vec, char* input_file, int& wordsToPrint){

    ifstream inFile(input_file);

    //checks if dictFile isnt opening
    if (!inFile)
        cout << input_file << " COULD NOT BE READ." << endl;

    int totalWords;

    inFile >> totalWords;
    inFile >> wordsToPrint;

    dsString line;
    char buffer[80] ={0};

    //while the file isnt at the end
    while(!inFile.eof()){
        inFile >> buffer;
        line = buffer;
        vec.push_back(line);
    }

    inFile.close();
}

void readandWrite::writeOutput(dsVector<dsString>& vec, char * output_file, int& wordsToPrint){
    ofstream outFile(output_file);

    if (!outFile)
        cout << output_file << " COULD NOT BE READ." << endl;

    for(int i = 0; i < wordsToPrint; i++){
        outFile << vec[i] << endl;
    }

    outFile.close();
}

readandWrite::~readandWrite(){


}

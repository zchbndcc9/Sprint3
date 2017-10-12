#include "readandwrite.h"
#include <fstream>
#include <iostream>

readandWrite::readandWrite(){

}

void readandWrite::readInput(dsString*& arr, char* input_file, int& wordsToPrint, int& totalWords){

    ifstream inFile(input_file);

    //checks if dictFile isnt opening
    if (!inFile)
        cout << input_file << " COULD NOT BE READ." << endl;

    inFile >> totalWords;
    inFile >> wordsToPrint;

    arr = new dsString[totalWords];

    dsString line;
    int i = 0;
    char buffer[80] ={0};

    //while the file isnt at the end
    while(!inFile.eof()){
        inFile >> buffer;
        arr[i] = buffer;
        i++;
    }

    inFile.close();
}

void readandWrite::writeOutput(dsString*& arr, char * output_file, int& wordsToPrint){
    ofstream outFile(output_file);

    if (!outFile)
        cout << output_file << " COULD NOT BE OPENED" << endl;

    for(int i = 0; i < wordsToPrint; i++){
        outFile << arr[i] << '\n';
    }

    outFile << endl;
    outFile.close();
}

readandWrite::~readandWrite(){


}

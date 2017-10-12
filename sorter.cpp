#include "sorter.h"

Sorter::Sorter() {

}

void Sorter::sort(){

}

void Sorter::readInput(char* input_file){

    ifstream inFile(input_file);

    //checks if dictFile isnt opening
    if (!inFile){
        cerr << input_file << " COULD NOT BE READ." << endl;
        return;
    }

    inFile >> totalWords;
    inFile >> wordsToSort;

    s_ptr = new dsString*[totalWords];

    dsString line;
    int i = 0;
    char buffer[80] ={0};

    //while the file isnt at the end
    while(!inFile.eof()){
        inFile >> buffer;
        s_ptr[i] = new dsString(buffer);
        i++;
    }

    inFile.close();
}

void Sorter::writeOutput(char* output_file){
    ofstream outFile(output_file);

    if (!outFile)
        cout << output_file << " COULD NOT BE OPENED" << endl;

    for(int i = 0; i < wordsToSort; i++){
        outFile << *(s_ptr[i]) << '\n';
    }

    outFile << endl;
    outFile.close();
}


Sorter::~Sorter(){
    for(int i = 0; i < totalWords; i++){
        delete s_ptr[i];
    }
    delete[] s_ptr;
}

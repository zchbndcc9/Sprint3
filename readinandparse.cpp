#include "readinandparse.h"
#include<fstream>
#include <iostream>
#include <algorithm>
#include <cstring>

readInAndParse::readInAndParse()
{
//default
}

//reads in dictionary file from argv[1]
void readInAndParse::readInput(char* input_file){

    ifstream inFile(input_file);

    //checks if dictFile isnt opening
    if (!inFile)
        cout <<"Houston we have a problem!!!!!!!!!!!" << endl;

    //can use index[0].w to call the variable or whatever in getPageNums
    char buffer[80];
    int totNums;
    int numsToPrint;
    dsString word;

    inFile >> totNums;
    inFile >> numsToPrint;
    //while the file isnt at the end
    while(!inFile.eof()){

        inFile.getline(buffer, 80);

        dsString line(buffer);


            int start = 0;
            //for loop for parsing words line by line
            for(int i = 0; i < line.size(); i++){

                //loops until end of word is found
                if((line[i] == ' ') || (line[i] == ']')
                        || (line[i+1] == '\0')) {

                    //handles the end of the line
                    if(line[i+1] == '\0'){
                        i++;
                    }

                     //creates a word from a substring
                     word = line.substring(start, i);


                    //adds words and page nums to vector
                    indexOfWords.push_back(word);


                    start = i + 1;

                }

            }


    }
    cout << totNums << endl;
    cout << numsToPrint << endl;
    for(int i = 0; i < indexOfWords.size(); i++){
        cout << indexOfWords[i]  << endl;
    }


 }
readInAndParse::~readInAndParse(){

}


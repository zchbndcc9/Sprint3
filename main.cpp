#include <iostream>
#include <chrono>
#include "readinandparse.h"
#include "algorithms.h"

using namespace std;

int main(int argc, char *argv[]) {

    Algorithms a;
    readInAndParse rh;
    dsVector<dsString> vec;
    int wordsToSort;

    rh.readInput(vec, argv[1], wordsToSort);

    cout << "Sorting..." << endl;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    a.quickSort(vec, 0, vec.size()-1);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();


    cout << "sorted." << '\n' << "time: " << duration << " microseconds" << '\n';

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}

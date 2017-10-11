#include <iostream>
#include <chrono>
#include "readandwrite.h"
#include "algorithms.h"

using namespace std;

int main(int argc, char *argv[]) {

    Algorithms a;
    readandWrite rh;
    dsString* arr;
    int wordsToSort, totalWords;

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    rh.readInput(arr, argv[1], wordsToSort, totalWords);

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    cout << duration << " milliseconds" << endl;

    cout << "Sorting..." << endl;
    t1 = std::chrono::high_resolution_clock::now();
    a.sortLength(arr, 0, totalWords - 1, wordsToSort);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();

     cout << "Sorted by length.  " << '\n' << "time: " << duration << " milliseconds" << '\n';

    t1 = std::chrono::high_resolution_clock::now();
    a.sortString(arr, 0, totalWords-1);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();

    cout << "Sorted alphabetically.  " << '\n' << "time: " << duration << " milliseconds" << '\n';

    t1 = std::chrono::high_resolution_clock::now();
    rh.writeOutput(arr, argv[2], wordsToSort);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    cout << duration << " milliseconds" << endl;
     delete[] arr;
}

#include <iostream>
#include <chrono>
#include "readandwrite.h"
#include "algorithms.h"

using namespace std;

int main(int argc, char *argv[]) {

    Algorithms a;
    readandWrite rh;
    dsVector<dsString> vec;
    int wordsToSort;

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    rh.readInput(vec, argv[1], wordsToSort);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << duration << " microseconds" << endl;

    cout << "Sorting..." << endl;
    t1 = std::chrono::high_resolution_clock::now();
    a.sortLength(vec, 0, vec.size()-1, wordsToSort);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

     cout << "Sorted by length.  " << '\n' << "time: " << duration << " microseconds" << '\n';

    t1 = std::chrono::high_resolution_clock::now();
    a.sortString(vec, 0, vec.size()-1);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    cout << "Sorted alphabetically.  " << '\n' << "time: " << duration << " microseconds" << '\n';

    t1 = std::chrono::high_resolution_clock::now();
    rh.writeOutput(vec, argv[2], wordsToSort);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << duration << " microseconds" << endl;
}

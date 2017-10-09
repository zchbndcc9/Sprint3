#include <iostream>
#include <chrono>
#include "readinandparse.h"
#include "algorithms.h"

using namespace std;

int main(int argc, char *argv[]) {

    int size = 100000;
    int * arr = new int[100000];

    for(int i = 0; i < size; i++){
        arr[i] = (rand() % 30) + 1;
    }


    Algorithms a;

    int tot = 0;
    cout << "Sorting..." << endl;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    a.quickSort(arr, 0, size - 1);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();


    cout << "sorted." << '\n' << "time: " << duration << " milli"
                                                         "seconds" << '\n';

//    readInAndParse rh;
//    rh.readInput(argv[1]);

    delete[] arr;
}

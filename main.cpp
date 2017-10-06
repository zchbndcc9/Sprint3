#include <iostream>
#include "readinandparse.h"
#include "algorithms.h"

using namespace std;

int main(int argc, char *argv[]) {
    int arr[100];

     cout << "Unsorted Array" << endl;
    for(int i = 0; i < 100; i++){
        arr[i] = (rand() % 100) + 1;

        cout << arr[i] << ' ';
    }


    Algorithms a;

    int size = 100;
    int tot = 0;
    a.quickSort(arr, 0, 99, tot, size);

    cout << '\n' << '\n' << endl;
     cout << "'Sorted' array" << endl;
    for(int i = 0; i < 100; i++){

        cout << arr[i] << ' ';
    }
    cout << '\n' << endl;
//    readInAndParse rh;
//    rh.readInput(argv[1]);


}

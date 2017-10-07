#include <iostream>
#include "readinandparse.h"
#include "algorithms.h"

using namespace std;

int main(int argc, char *argv[]) {


    int size = 10;
    int arr[10];

     cout << "Unsorted Array" << endl;
    for(int i = 0; i < size; i++){
        arr[i] = (rand() % 5) + 1;

        cout << arr[i] << ' ';
    }


    Algorithms a;

    int tot = 0;
    a.quickSort(arr, 0, size - 1, tot, size);

    cout << '\n' << '\n' << endl;
     cout << "'Sorted' array" << endl;
    for(int i = 0; i < size; i++){

        cout << arr[i] << ' ';
    }
    cout << '\n' << endl;
//    readInAndParse rh;
//    rh.readInput(argv[1]);


}

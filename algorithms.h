#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <cstring>

class Algorithms {
public:
    void quickSort(int arr[], int, int);
    void partition(int[], int, int, int&, int&, int&);
    void twoWayPart(int[], int, int, int&, int&);
    void sortLength();
    void sortString();
    int medianOfThree(int[], int, int);
    inline void swap(int*, int*);
};

#endif // ALGORITHMS_H

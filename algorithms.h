#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <cstring>

class Algorithms {
public:
    void quickSort(int[], int, int);
    void dualPivot(int[], int, int, int&, int&);
    void sortLength();
    void sortString();
    int medianOfThree(int[], int, int);
    bool isSorted(int[], int, int);
    inline void swap(int*, int*);
};

#endif // ALGORITHMS_H

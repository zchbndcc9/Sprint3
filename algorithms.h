#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <dsvector.h>
#include <dsstring.h>

class Algorithms {
public:
    void quickSort_Length(dsString*&, int, int);
    void dualPivot_Length(dsString*&, int, int, int&, int&);
    void quickSort_String(dsString*&, int, int);
    void dualPivot_String(dsString*&, int, int, int&, int&);

    int medianOfThree(const dsString*&, int, int);

    void insertionSort(dsString*&, int, int);

    void sortLength(dsString*&, int, int, int);
    void sortString(dsString*&, int, int);

    bool isSorted_Length(const dsString*, int, int);
    bool isSorted(const dsString*, int, int);

    template <class T>
    inline void swap(T* a, T* b){
        T temp = *a;
        *a = *b;
        *b = temp;
    }
};

#endif // ALGORITHMS_H

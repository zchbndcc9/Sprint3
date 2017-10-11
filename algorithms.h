#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <dsvector.h>
#include <dsstring.h>

class Algorithms {
public:
    void quickSort_Length(dsVector<dsString>&, int, int);
    void dualPivot_Length(dsVector<dsString>&, int, int, int&, int&);
    void quickSort_String(dsVector<dsString>&, int, int);
    void dualPivot_String(dsVector<dsString>&, int, int, int&, int&);

    int medianOfThree(const dsVector<dsString>&, int, int);

    void insertionSort(dsVector<dsString>&, int, int);

    void sortLength(dsVector<dsString>&, int, int, int);
    void sortString(dsVector<dsString>&, int, int);

    bool isSorted_Length(const dsVector<dsString>&, int, int);
    bool isSorted(const dsVector<dsString>&, int, int);

    template <class T>
    inline void swap(T* a, T* b){
        T temp = *a;
        *a = *b;
        *b = temp;
    }
};

#endif // ALGORITHMS_H

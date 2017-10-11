#include "algorithms.h"

void Algorithms::quickSort_Length(dsString*& arr, int low, int high){
    if(low >= high)
        return;

    int i, j;

    dualPivot_Length(arr, low, high, i, j);

    quickSort_Length(arr, low, i - 1);
    //checks middle to see if it is sorted or not
    if(!isSorted_Length(arr, i + 1, j - 1))
        quickSort_Length(arr, i + 1, j - 1);
    quickSort_Length(arr, j + 1, high);
}

void Algorithms::dualPivot_Length(dsString*& arr, int low, int high, int& left, int& right){
    if(arr[low].size() > arr[high].size())
        swap(&arr[high], &arr[low]);

    //traverse left to right
    int lp, i;
    //traverse right to left
    int rp;

    left = i = low + 1;
    right = high - 1;

    //Left pivot
    lp = arr[low].size();
    //Right pivot
    rp = arr[high].size();

    while(i <= right){
        //traverse from left to right
        if(arr[i].size() < lp){
            swap(&arr[i++], &arr[left++]);
        } else if(arr[i].size() > rp){
            swap(&arr[i], &arr[right--]);
        } else {
            i++;
        }
    }

    swap(&arr[low], &arr[--left]);
    swap(&arr[high], &arr[++right]);
}

void Algorithms::quickSort_String(dsString*& arr, int low, int high){
    if(low >= high)
        return;

    int i, j;

    dualPivot_String(arr, low, high, i, j);

    quickSort_String(arr, low, i - 1);
    //checks middle to see if it is sorted or not
    quickSort_String(arr, i + 1, j - 1);
    quickSort_String(arr, j + 1, high);
}

void Algorithms::dualPivot_String(dsString*& arr, int low, int high, int& left, int& right){
    if(arr[low] > arr[high])
        swap(&arr[high], &arr[low]);

    int i;
    //traverse left to right
    dsString lp;
    //traverse right to left
    dsString rp;

    left = i = low + 1;
    right = high - 1;

    //Left pivot
    lp = arr[low];
    //Right pivot
    rp = arr[high];

    while(i <= right){
        //traverse from left to right
        if(lp > arr[i]){
            swap(&arr[i++], &arr[left++]);
        } else if(arr[i] > rp){
            swap(&arr[i], &arr[right--]);
        } else {
            i++;
        }
    }

    swap(&arr[low], &arr[--left]);
    swap(&arr[high], &arr[++right]);
}

int Algorithms::medianOfThree(const dsString*& arr, int low, int high){
    int mid = (high+low)/2;

    if(arr[high] > arr[low]) {
        return (arr[low] > arr[mid]) ? low : mid;
    } else {
        return (arr[mid] > arr[high]) ? mid : high;
    }
}

void Algorithms::insertionSort(dsString*& arr, int low, int high){
    for(int i = low + 1; i <= high; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

void Algorithms::sortLength(dsString*& arr, int low, int high, const int wordsToSort){
    int wordsSorted = 0;

    quickSort_Length(arr, low, high);
}

void Algorithms::sortString(dsString*& arr, int low, int high){
    int i = low;
    int j = low;

    while(j < high){
        if(arr[j+1].size() > arr[j].size()){
            //if less than 30, insertion sort
            ((j - i) <= 29) ? insertionSort(arr, i, j) :
                              quickSort_String(arr, i, j);
            i = j + 1;
            j++;
        } else {
            j++;
        }
    }
}

bool Algorithms::isSorted_Length(const dsString* arr, int low, int high){
    for(int i = low; i < (high - 1); i++){
        if(arr[i].size() > arr[i+1].size())
            return false;
    }

    return true;
}

bool Algorithms::isSorted(const dsString* arr, int low, int high){
    for(int i = low; i < (high - 1); i++){
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

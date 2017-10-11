#include "algorithms.h"

void Algorithms::quickSort_Length(dsVector<dsString>& vec, int low, int high){
    if(low >= high)
        return;

    int i, j;

    dualPivot_Length(vec, low, high, i, j);

    quickSort_Length(vec, low, i - 1);
    //checks middle to see if it is sorted or not
    if(!isSorted_Length(vec, i + 1, j - 1))
        quickSort_Length(vec, i + 1, j - 1);
    quickSort_Length(vec, j + 1, high);
}

void Algorithms::dualPivot_Length(dsVector<dsString>& vec, int low, int high, int& left, int& right){
    if(vec[low].size() > vec[high].size())
        swap(&vec[high], &vec[low]);

    //traverse left to right
    int lp, i;
    //traverse right to left
    int rp;

    left = i = low + 1;
    right = high - 1;

    //Left pivot
    lp = vec[low].size();
    //Right pivot
    rp = vec[high].size();

    while(i <= right){
        //traverse from left to right
        if(vec[i].size() < lp){
            swap(&vec[i++], &vec[left++]);
        } else if(vec[i].size() > rp){
            swap(&vec[i], &vec[right--]);
        } else {
            i++;
        }
    }

    swap(&vec[low], &vec[--left]);
    swap(&vec[high], &vec[++right]);
}

void Algorithms::quickSort_String(dsVector<dsString>& vec, int low, int high){
    if(low >= high)
        return;

    int i, j;

    dualPivot_String(vec, low, high, i, j);

    quickSort_String(vec, low, i - 1);
    //checks middle to see if it is sorted or not
    if(!isSorted(vec, i + 1, j - 1))
        quickSort_String(vec, i + 1, j - 1);
    quickSort_String(vec, j + 1, high);
}

void Algorithms::dualPivot_String(dsVector<dsString>& vec, int low, int high, int& left, int& right){
    if(vec[low] > vec[high])
        swap(&vec[high], &vec[low]);

    int i;
    //traverse left to right
    dsString lp;
    //traverse right to left
    dsString rp;

    left = i = low + 1;
    right = high - 1;

    //Left pivot
    lp = vec[low];
    //Right pivot
    rp = vec[high];

    while(i <= right){
        //traverse from left to right
        if(lp > vec[i]){
            swap(&vec[i++], &vec[left++]);
        } else if(vec[i] > rp){
            swap(&vec[i], &vec[right--]);
        } else {
            i++;
        }
    }

    swap(&vec[low], &vec[--left]);
    swap(&vec[high], &vec[++right]);
}

int Algorithms::medianOfThree(const dsVector<dsString>& vec, int low, int high){
    int mid = (high+low)/2;

    if(vec[high] > vec[low]) {
        return (vec[low] > vec[mid]) ? low : mid;
    } else {
        return (vec[mid] > vec[high]) ? mid : high;
    }
}

void Algorithms::insertionSort(dsVector<dsString>& vec, int low, int high){
    for(int i = low + 1; i < high; i++){
        int j = i;
        while(j > 0 && vec[j-1] > vec[j]){
            swap(&vec[j], &vec[j-1]);
            j--;
        }
    }
}

void Algorithms::sortLength(dsVector<dsString>& vec, int low, int high, const int wordsToSort){
    int wordsSorted = 0;

   // quickSort(vec, low, high, wordsSorted, wordsToSort);
}

void Algorithms::sortString(dsVector<dsString>& vec, int low, int high){
    //if less than 30, insertion sort
    if((high - low) >= 29){
        insertionSort(vec, low, high);
    } else {
        quickSort_String(vec, low, high);
    }
}

bool Algorithms::isSorted_Length(const dsVector<dsString>& vec, int low, int high){
    for(int i = low; i < (high - 1); i++){
        if(vec[i].size() > vec[i+1].size())
            return false;
    }

    return true;
}

bool Algorithms::isSorted(const dsVector<dsString>& vec, int low, int high){
    for(int i = low; i < (high - 1); i++){
        if(vec[i] > vec[i+1])
            return false;
    }

    return true;
}

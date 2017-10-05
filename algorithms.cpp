#include "algorithms.h"

void Algorithms::quickSort(int arr[], int low, int high, int& tot, int& fSize){
    if(low < high){
        int i, j;

        partition(arr, low, high, i, j, tot);

        quickSort(arr, low, j, tot, fSize);
        quickSort(arr, i, high, tot, fSize);
    }
}

void Algorithms::partition(int arr[], int low, int high, int& i, int& j, int& tot){
    int p, q, pivot = medianOfThree(arr, low, high);

    i = p = low + 1;
    j = q = high;

    if(pivot != low) {
        swap(&arr[low], &arr[pivot]);
    }

    pivot = arr[low];

    //loop until indices cross
    while(true){

        while(arr[i] < pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
            if(j == low)
                break;
        }

        if(i > j)
            break;

        swap(&arr[i], &arr[j]);

        //check pivot
        if(arr[i] == pivot){
            swap(&arr[p], &arr[i]);
            p++;
        } else if(arr[j] == pivot){
            swap(&arr[q], &arr[j]);
            q--;
        }
    }

    if(p != low){
        p--;
        //transfer pivot ends to middle
        for(p; p >= low; p--, j--){
            swap(&arr[p], &arr[j]);
        }
    }

    if(q != high){
        q++;
        for(q; q <= high; q++, i++){
            swap(&arr[q], &arr[i]);
        }
    }

    //add sorted to total
    tot += (i - j) - 1;
}

void Algorithms::sortLength(){

}

void Algorithms::sortString(){

}

int Algorithms::medianOfThree(int arr[], int low, int high){
    int mid = (high+low)/2;

    if(arr[high] > arr[low]) {
        return (arr[low] > arr[mid]) ? low : mid;
    } else {
        return (arr[mid] > arr[high]) ? mid : high;
    }
}

void Algorithms::swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



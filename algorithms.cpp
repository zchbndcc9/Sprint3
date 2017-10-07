#include "algorithms.h"
using namespace std;
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

    //SPLIT UP THESE VARIABLE DECLARATIONS
    i = low + 1;
    p = i;
    j = high;
    q = j;


    if(pivot != low) {
        swap(&arr[low], &arr[pivot]);
    }

    pivot = arr[low];


    //loop until indices cross
    while(true){
        //i starts at
        while(arr[i] < pivot) {
            i++;
        }

        //ZACH: This function essentially overwrites other data in array
        //ADDED THIS FUCTION
       if(arr[i]== pivot){
            arr[i-1] = arr[i];
        }
       //END OF ADDED FUNCTION


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
            p++;
            //CHANGED THESE VARIABLES FROM (P?) TO I
        } else if(arr[j] == pivot){
            q--;
            //CHANGED THESE VARIABLES FROM (Q?) TO J
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



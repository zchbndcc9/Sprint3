#include "algorithms.h"

void Algorithms::quickSort(int arr[], int low, int high){
    if(low >= high)
        return;

    int i, j;

    dualPivot(arr, low, high, i, j);

    quickSort(arr, low, i - 1);
    //checks middle to see if it is sorted or not
    if(!isSorted(arr, i + 1, j - 1))
        quickSort(arr, i + 1, j - 1);
    quickSort(arr, j + 1, high);

}

void Algorithms::dualPivot(int arr[], int low, int high, int& left, int& right){


    if(arr[low] > arr[high])
        swap(&arr[high], &arr[low]);

   //traverse left to right
     int lp, i;
   //traverse right to left
     int rp;

     left = i = low + 1;
     right = high - 1;

   //Left pivot
     lp = arr[low];
   //Right pivot
     rp = arr[high];

     while(i <= right){
       //traverse from left to right
         if(arr[i] < lp){
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

bool Algorithms::isSorted(int arr[], int low, int high){
    for(int i = low; i < (high - 1); i++){
        if(arr[i] > arr[i+1])
            return false;
    }

    return true;
}

void Algorithms::swap(int* a, int* b){
    int temp = *a;

    *a = *b;
    *b = temp;
}



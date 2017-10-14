#include "algorithms.h"

void Algorithms::quickSort_Length(dsString**& arr, int low, int high){
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

void Algorithms::dualPivot_Length(dsString**& arr, int low, int high, int& lt, int& gt){
    if(arr[low]->size() > arr[high]->size())
        swap(&arr[high], &arr[low]);

    //traverse left to right
    int lp, i;
    //traverse right to left
    int rp;

    lt = i = low + 1;
    gt = high - 1;

    //Left pivot
    lp = arr[low]->size();
    //Right pivot
    rp = arr[high]->size();

    while(i <= gt){
        //traverse from left to right
        if(arr[i]->size() < lp){
            swap(&arr[i++], &arr[lt++]);
        } else if(arr[i]->size() > rp){
            swap(&arr[i], &arr[gt--]);
        } else {
            i++;
        }
    }

    swap(&arr[low], &arr[--lt]);
    swap(&arr[high], &arr[++gt]);
}

void Algorithms::quickSort_String(dsString**& arr, int low, int high, int ch){
    if(low >= high)
        return;

    char v;
    int i, j;

    partition_threeWay(arr, low, high, i, j, v, ch);

    quickSort_String(arr, low, j - 1, ch);
    if(i == high && (*arr[i])[ch] == v)
        i++;
    //checks middle to see if it is sorted or not
    if(v >= 0)
        quickSort_String(arr, j, i, ch + 1);
    quickSort_String(arr, i + 1, high, ch);
}

void Algorithms::partition_threeWay(dsString**& arr, int low, int high, int& lt, int& gt, char& piv, int iChar){
    //iterators to indicate ramge of strings with a value
    //equal to pivot char
    int p, q;

    //Start on left
    p = low - 1;
    lt = low - 1;

    //Start on right
    q = high;
    gt = high;

    //character used as pivot
    piv = (*arr[high])[iChar];

    while(lt < gt){
        while((*arr[++lt])[iChar] < piv){
            if(lt == high)
                break;
        }
        while((*arr[--gt])[iChar] > piv){
            if(gt == low)
                break;
        }
        if(lt > gt)
            break;
        swap(&arr[lt], &arr[gt]);

        if((*arr[lt])[iChar] == piv)
            swap(&arr[lt], &arr[++p]);
        if((*arr[gt])[iChar] == piv)
            swap(&arr[gt], &arr[--q]);
    }

    if(p == q){
        if (piv > 0){
            int i = lt;
            quickSort_String(arr, low, high, iChar + 1);
            return;
        }
    }

    if((*arr[lt])[iChar] > piv)
        lt++;

    for(int k = low; k <= p; k++){
        swap(&arr[k], &arr[gt--]);
    }
    for(int k = high; k >= q; k--){
        swap(&arr[k], &arr[lt++]);
    }
}

int Algorithms::medianOfThree(const dsString**& arr, int low, int high){
    int mid = (high+low)/2;

    if(arr[high] > arr[low]) {
        return (arr[low] > arr[mid]) ? low : mid;
    } else {
        return (arr[mid] > arr[high]) ? mid : high;
    }
}

void Algorithms::insertionSort(dsString**& arr, int low, int high){
    if(low >= high)
        return;
    for(int i = low + 1; i <= high; i++){
        int j = i;
        while(j > low && *(arr[j-1]) > *(arr[j])){
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

void Algorithms::sortLength(dsString**& arr, int low, int high) {
    int wordsSorted = 0;

    quickSort_Length(arr, low, high - 1);
}

void Algorithms::sortString(dsString**& arr, int low, int high){
    int i = low;
    int j = low;

    //MAKE GO FAST AND CONDENSE
    while(j < high){
        if(arr[j]->size() > arr[i]->size()){
            //if less than 30, insertion sort
            ((j - i) <= 29) ? insertionSort(arr, i, j - 1) : quickSort_String(arr, i, j - 1, 0);
            i = j;
        } else if(j == high - 1){
            ((j - i) <= 29) ? insertionSort(arr, i, j) : quickSort_String(arr, i, j, 0);
            i = j;
            j++;
        } else {
            j++;
        }
    }
}

bool Algorithms::isSorted_Length(dsString** arr, int low, int high){
    for(int i = low; i < (high - 1); i++){
        if(arr[i]->size() > arr[i+1]->size())
            return false;
    }

    return true;
}

bool Algorithms::isSorted(dsString** arr, int low, int high){
    for(int i = low; i < (high - 1); i++){
        if(*(arr[i]) > *(arr[i+1]))
            return false;
    }
    return true;
}

#include <iostream>
#include <cstdlib>
#include "arraylist.h"
using namespace std;

void bucketSort(int* arr, int n);
void insertion_sort(int* arr, int size);

int main (){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i= 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "UNSORTED ARRAY\n";
    for (int i= 0; i < n; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;

    bucketSort(arr, n);

    cout << "SORTED ARRAY\n";
    for (int i= 0; i < n; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bucketSort(int* arr, int n){
    /* create 10 buckets 
    /* could be any number of buckets, depending on what you want/need */
    ArrayList* buckets[10];
    /* bucket 0: 0-9      bucket 5: 50-59 
    /* bucket 1: 10-19    bucket 6: 60-69 
    /* bucket 2: 20-29    bucket 7: 70-79 
    /* bucket 3: 30-39    bucket 8: 80-89 
    /* bucket 4: 40-49    bucket 9: 90-99   */

    for (int i = 0; i < 10; i++){
        /* initializing each bucket to hold n number of elements */
        buckets[i] = new ArrayList(n);
    }

    for (int i = 0; i < n; i++){
        // determining which bucket i-put ang element
        int bucketIndex = arr[i] / 10;

        // adding the element to the appropriate bucket
        buckets[bucketIndex] -> add(arr[i]);
    }

    int i = 0;
    // for each bucket, do sorting
    for (ArrayList* bucket: buckets){
        /* for proof lang nga asa sila na buckets nakabutang */
        cout << "BUCKET " << i << " | ";
        i++;
        bucket -> print();

        /* SORT */
        bucket -> insertionSort();
    }

    int new_index = 0;

    // get elements from buckets
    for (ArrayList* bucket: buckets){
        for (int i = 0; i < bucket->_size(); i++){
            arr[new_index++] = bucket->get(i);
        }
    }
    

    /* bucket sort using 2d array for buckets 
    /* create 10 buckets with size n */

    // int buckets[10][n];

    /* int array to keep track of each bucket size */
    // int *bucketSizes = (int*) calloc(10, sizeof(int));

    // for (int i = 0; i < n; i++){
    //     int bucketIndex = arr[i]/10;

    //     int bucketSize = bucketSizes[bucketIndex];

    //     buckets[bucketIndex][bucketSize] = arr[i]; 

    //     (bucketSizes[bucketIndex])++;
    // }

    // for(int i = 0; i < 10; i++){
    //     insertion_sort(buckets[i], bucketSizes[i]);
    // }

    // int new_arr_index = 0;
    // for (int j = 0; j < 10; j++){
    //     for (int k = 0; k < bucketSizes[j]; k++){
    //         arr[new_arr_index++] = buckets[j][k];
    //     }
    // }
}

void insertion_sort(int* arr, int size){
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
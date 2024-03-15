#include <iostream>
#include "arraylist.h"

using namespace std;

void bucketsort(double *array, int size);

int main()
{
    int size = 20;
    double array[] = {0.812748, 0.379421, 0.120535, 0.984107, 0.652893,
                      0.291764, 0.048231, 0.435918, 0.760254, 0.506379,
                      0.213094, 0.951827, 0.718501, 0.179358, 0.625132,
                      0.471809, 0.097564, 0.343279, 0.870123, 0.586910};
    // int size;
    // cout << "Enter size of array: ";
    // cin >> size;
    // int array[size];

    // cout << "Enter elements: ";
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> array[i];
    // }

    cout << endl
         << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    bucketsort(array, size);

    cout << endl
         << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

void bucketsort(double *array, int size)
{
    cout << endl
         << endl;
    // intialize de buckets
    ArrayList *buckets[10];
    for (int i = 0; i < 10; i++)
    {
        buckets[i] = new ArrayList(size);
    }

    // place elements on designated buckets
    /*
    .0 = bucket[0] .5 = bucket[5]
    .1 = bucket[1] .6 = bucket[6]
    .2 = bucket[2] .7 = bucket[7]
    .3 = bucket[3] .8 = bucket[8]
    .4 = bucket[4] .9 = bucket[9]
    */
    for (int i = 0; i < size; i++)
    {
        // Multiplied by to to get index based on decimal value
        int index = array[i] * 10;
        // kadtong chuy na word ana () yawa so that..
        buckets[(int)index]->add(array[i]);
    }

    // sorts de buckets using da inzertion short
    int i = 0;
    for (ArrayList *b : buckets)
    {
        cout << "BUCKET " << i << " | ";
        i++;
        b->print();
        b->insertionSort();
    }

    // Concatenate bucketsz
    int newIndex = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < buckets[i]->_size(); j++)
        {
            array[newIndex] = buckets[i]->get(j);
            cout << array[newIndex] << " ";
            newIndex++;
        }
        cout << endl;
    }
}

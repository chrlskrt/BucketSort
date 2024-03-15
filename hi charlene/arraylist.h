#include <iostream>
#include <cstdlib>
using namespace std;

class ArrayList
{
    double *array;
    int capacity;
    int size = 0;

public:
    ArrayList(int cap)
    {
        capacity = cap;
        array = new double[cap];
    }

    void add(double num)
    {
        array[size] = num;
        size++;
    }

    int _size()
    {
        return size;
    }

    double get(int index)
    {
        return array[index];
    }

    void insertionSort()
    {
        double key; // Use double for key
        int j;
        for (int i = 1; i < size; i++)
        {
            key = array[i];
            j = i - 1;

            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }

    void print()
    {
        cout << "Size: " << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

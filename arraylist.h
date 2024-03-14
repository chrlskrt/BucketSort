#include <iostream>
#include <cstdlib>
using namespace std;

class ArrayList {
	int* array;
	int capacity;
	int size = 0;
	
	public:
	ArrayList(int cap) {
		capacity = cap;
		array = new int[cap];
	}
	
	void insertionSort(){
		int key, j;
		for (int i = 1; i < size; i++){
			key = array[i];
			j = i - 1;

			while (j >= 0 && array[j] > key){
				array[j+1] = array[j];
				j = j - 1;
			}

			array[j+1] = key;
		}
	}

	
	void add(int num) {
		array[size] = num;
		size++;	
	}

	int _size() {
		return size;
	}
	
	int get(int index) {
		return array[index];
	}
	
	void print() {
		cout << "Size: " << size << endl;
		for (int i = 0; i < capacity; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

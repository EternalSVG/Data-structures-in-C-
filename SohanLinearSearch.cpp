/*
By: Sohan Yarlagadda, Professor Cuevas
CS 41 Data Structures, Fall 2024

Search an un-ordered array an integers for a value, if the value is found return the index of its position in the array, if not found, return -1.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Generated array: ";
  
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int value;
    cout << "Enter a value to search for: ";
    cin >> value;

    int index = linearSearch(arr, SIZE, value);

    if (index != -1) {
        cout << "The value " << value << " was found at index " << index << "." << endl;
    } else {
        cout << "The value " << value << " was not found in the array." << endl;
    }

    return 0;
}
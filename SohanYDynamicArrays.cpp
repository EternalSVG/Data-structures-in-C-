/*
By: Sohan Yarlagadda
CS 41 Data Structures, Professor Cuevas
Fall 2024

Objective:  Create an array of numbers based upon user input.

Program logic:
Ask the user for how big to size the array.
Create an array based upon that size.
Ask for a number, add that number to the array.
Repeat adding to the end until all numbers have been entered or until they enter -1 for the number.
Print the list.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "\n" "Enter the numbers for the array (enter -1 to stop): ";

    int num;
    int count = 0;

    while (count < size) {
        cin >> num;

        if (num == -1) {
            break;
        }
        
        arr[count] = num;
        count++;
    }
    cout << "\n" "The array is: ";

    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    delete[] arr;
    
    return 0; 
}


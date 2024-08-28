/*
By: Sohan Yarlagadda
CS 41 Data Structures, Professor Cuevas
Fall 2024

Create a class/struct.

Members:
MaxSize const = 10
Define an array that holds 10 items.
Count - indicates how many items are on the queue.
Front - where the front of the queue is in the array. 
Back - Where the end of the queue is in the array. 


Methods:
En-queue O(1)
- Accepts a number and adds to the end of the queue.
- If the queue is full emit an error indicating full.
De-queue O(1)
- Returns a number from the front of the queue.
- If the queueis empty, emit an error indicating the queueis empty.
IsEmpty
- Returns a boolean indicating if the queue is empty.
*Note that the front and back can wrap around the end of the array over time. 
*/

#include <iostream>
#include <stdexcept>

using namespace std;

class Queue {
private:
    static const int MaxSize = 10; 
    int arr[MaxSize];              
    int count;                     
    int front;                     
    int back;                      

public:
    Queue();                       
    void enqueue(int item);        
    int dequeue();                 
    bool isEmpty();                
};

Queue::Queue() : count(0), front(0), back(0) {}

void Queue::enqueue(int item) {
    if (count == MaxSize) {
        throw runtime_error("Queue is full.");
    }
    arr[back] = item;
    back = (back + 1) % MaxSize;
    count++;
}

int Queue::dequeue() {
    if (count == 0) {
        throw runtime_error("Queue is empty.");
    }
    int item = arr[front];
    front = (front + 1) % MaxSize;
    count--;
    return item;
}

bool Queue::isEmpty() {
    return count == 0;
}

int main() {
    Queue q;

    // Enqueue 10 numbers
    for (int i = 1; i <= 10; ++i) {
        q.enqueue(i);
    }

    // Dequeue and print all numbers
    while (!q.isEmpty()) {
        cout << q.dequeue() << endl;
    }

    return 0;
}

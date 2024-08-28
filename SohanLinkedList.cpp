/*
By: Sohan Yarlagadda, Professor Cuevas
CS 41 Data Structures, Fall 2024

Objective:  Create a singly linked list of numbers based upon user input.

Program logic:
Ask for a number, add that number to the front of the list, print the list.
Repeat until they enter -1 for the number.
.
Sample Input: 10, 15, 5, 2, 4, -1
Output: 4, 2, 5, 15, 10
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertAtFront(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

int main() {
    Node* head = nullptr;
    int num;

    cout << "Enter a number (-1 to stop): ";
    cin >> num;

    while (num != -1) {
        insertAtFront(head, num);
        
        cout << "Enter a number (-1 to stop): ";
        cin >> num;
    }
    cout << "\n" << "List: ";
    printList(head);
    return 0;
}
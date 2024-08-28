/*
By: Sohan Yarlagadda, Professor Cuevas
CS 41 Data Structures, Fall 2024

Objective:  Create a sorted singly linked list of numbers based upon user input.

Program logic:
Ask for a number, add that number to the list in sorted position, print the list.
Repeat until they enter -1 for the number.
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertSorted(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
    } else if (value == head->data) {
        delete newNode;
        return;
    } else if (value > head->data) {
        Node* current = head;

        while (current->next != nullptr && value > current->next->data) {
            current = current->next;
        }

        if (current->next == nullptr || value < current->next->data) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            delete newNode;
        }
    }
}

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    Node* head = nullptr;
    int num;

    cout << "Enter a number (-1 to stop): ";
    cin >> num;

    while (num != -1) {
        insertSorted(head, num);
        
        cout << "List: ";
        printList(head);
        
        cout << "Enter a number (-1 to stop): ";
        cin >> num;
    }
    return 0;
}

/*
By: Sohan Yarlagadda

Create a class/struct for a node.
Create a class/struct for a list.

Members:
Top - a node that tracks the top of the stack
Count - indicates how many items are on the stack.

Methods:
Push O(1)
- Accepts a number and adds to the top of the stack.
Pop O(1)
- Returns a number from the top of the stack.
- If the stack is empty, emit an error indicating the stack is empty.
IsEmpty
- Returns a boolean indicating if the stack is empty.

Create and exercise a stack object in main.
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
    int count;

public:
    Stack() {
        top = nullptr;
        count = 0;
    }

    void push(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        } else {
            int value = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            count--;
            return value;
        }
    }

    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl; 
    cout << stack.pop() << endl; 

    return 0;
}

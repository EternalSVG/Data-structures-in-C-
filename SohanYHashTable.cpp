/*
 Hash Table
 */

#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

// Hash table for key-value pairs.
struct HashNode {
    int key;
    string value;
    
    HashNode(int k, const string& v) : key(k), value(v) {}
};

// Creating a hash table class with chaning for collision resolution.
class HashTable {
private:
    vector<list<HashNode>> table;
    int size;
    
    // Function for hash.
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Creating a contructor.
    HashTable(int s) : size(s) {
        table.resize(size);
    }
    
    // Adding a key-value pair to the hash table.
    void add(int key, const string& value) {
        int hashIndex = hashFunction(key);
        
        // Using a for loop, check if any key already exists.
        for (auto& node : table[hashIndex]) {
            if (node.key == key) {
                node.value = value;
                cout << "Updated key " << key << " with new value: " << value << endl;
                return;
            }
        }
        
        // If key is not found, insert a new entry.
        table[hashIndex].emplace_back(key, value);
        cout << "Added key " << key << " with value: " << value << endl;
    }
    
    // Look up a value using its key.
    string lookup(int key) {
        int hashIndex = hashFunction(key);
        
        for (const auto&node : table[hashIndex]) {
            if (node.key == key) {
                return node.value;
            }
        }
        return "Key not found.";
    }
    
    // Creating a function to delete a key-valye pair from the hash table.
    string deleteKey(int key) {
        int hashIndex = hashFunction(key);
        auto& chain = table[hashIndex];
        
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->key == key) {
                string value = it->value;
                chain.erase(it);
                cout << "Deleted key " << key << " with value: " << value << endl;
                return value;
            }
        }
        return "Key not found";
    }
    
    // Create a function to display the contents of the hash table.
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& node: table[i]) {
                cout << "(" << node.key << ", " << node.value << ")";
            }
            cout << endl;
        }
    }
};


int main() {
    int tableSize = 10;
    HashTable hashTable(tableSize);
    int choice;
    int key;
    string value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add (int, string)\n";
        cout << "2. Lookup (int)\n";
        cout << "3. Delete (int)\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key (int): ";
                cin >> key;
                cout << "Enter value (string): ";
                cin.ignore();
                getline(cin, value);
                hashTable.add(key, value);
                break;
            case 2:
                cout << "Enter key (int) to lookup: ";
                cin >> key;
                cout << "Value: " << hashTable.lookup(key) << endl;
                break;
            case 3:
                cout << "Enter key (int) to delete: ";
                cin >> key;
                cout << "Deleted Value: " << hashTable.deleteKey(key) << endl;
                break;
            case 4:
                hashTable.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

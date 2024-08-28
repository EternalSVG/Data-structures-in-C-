/*
By: Sohan Yarlagadda, CS 41 Data Structures, Professor Cuevas
Fall 2024

Read a sentence from the console.
Break the sentence into words using the space character as a delimiter.
Iterate over each word, if the word is a numeric value then print its value doubled, otherwise print out the word, with each output on its own line.


Sample Run:
Sentence: Hello world, there are 3.5 items.


Output:
Hello
world,
there
are
7
items.
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string sentence;
    cout << "Enter your sentence: ";

    getline(cin, sentence);
    istringstream iss(sentence);

    string word;

    while (iss >> word) {
        try {
            double num = stod(word);
            cout << num * 2 << endl;
        } catch (const invalid_argument&) {
            cout << word << endl;
        }
    }
    return 0;
}

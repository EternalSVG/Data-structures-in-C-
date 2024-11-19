/*
 Build a run length encoding program.
 Write a function that takes a string and returns the encoded string using run lengthencoding.
 In main, prompt the user for a string.
 Output the encoded string.
 Output the compression rate.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string runLengthEncode(const string& input) {
    string encoded = "";
    std::size_t n = input.length();
    
    for (std::size_t i = 0; i < n; ++i) {
        int count = 1;
        while (i + 1 < n && input[i] == input[i + 1]) {
            ++count;
            ++i;
        }
        
        encoded += input[i];
        encoded += to_string(count);
    }
    return encoded;
}

int main() {
    string input;
    cout << "Enter a string to encode: ";
    getline(cin, input);
    
    string encoded = runLengthEncode(input);
    
    double compressionRate = (1.0 - (static_cast<double>(encoded.length()) / input.length())) * 100;
    
    cout << "Encoded string: " << encoded << endl;
    cout << fixed << setprecision(2);
    cout << "Compression rate: " << compressionRate << "%" << endl;
    
    return 0;
}



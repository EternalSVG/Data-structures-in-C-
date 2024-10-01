/*
 CS 41 Data Structures
 Version: 09.17.2024
 
 Program Description:
 Create a matrix based graph representation.

 It will need to support the following operations.
 Ask the user how many points there are.
 Ask the user to label those points, ie "A", "B", "C"...
 Define the matrix as a square matrix based on the number of points, also keep an array of the labels.
 Repeatedly ask the user to define edges between two points. Add these edges to the matrix.
 Have a list method that will list out all of the edges in the graph.
 Sample Graph Lab Flow:

 How many vertices? 6
 What is the label for vertex 1? A
 What is the label for vertex 2? B
 What is the label for vertex 3? C
 What is the label for vertex 4? D
 What is the label for vertex 5? E
 What is the label for vertex 6? F

 Define an edge by listing a pair of vertices, i.e. "A B", or -1 to stop.
 A B
 Added Edge A->B
 B A
 Added Edge B->A
 -1

 Your edges are: AB, BA
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Graph {
public:
    int numVertices;
    vector<string> labels;
    vector<vector<int>> adjMatrix;

    // Constructor to initialize the graph with a number of vertices.
    Graph(int vertices) {
        numVertices = vertices;
        labels.resize(vertices);
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }
    
    // Declaring a function to set labels for each vertex.
    void setLabels() {
        for (int i = 0; i < numVertices; i++) {
            cout << "What is the label for vertex " << (i + 1) << "? ";
            cin >> labels[i];
        }
    }
    
    // Function to add an edge between two vertices.
    void addEdge(string vertex1, string vertex2) {
        int v1 = findVertex(vertex1);
        int v2 = findVertex(vertex2);
        
        if (v1 != -1 && v2 != -1) {
            adjMatrix[v1][v2] = 1;
            cout << "Added edge: " << vertex1 << "->" << vertex2 << endl;
        } else {
            cout << "Invalid vertices." << endl;
        }
    }
    
    // Declaring a function to list all the edges in a graph.
    void listEdges() {
        cout << "Your edges are: ";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    cout << labels[i] << labels[j] << ", ";
                }
            }
        }
        cout << endl;
    }

private:
    // Function to find the index of a vertex from its label.
    int findVertex(string vertex) {
        for (int i = 0; i < numVertices; i++) {
            if (labels[i] == vertex) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int vertices;
    
    // Asking the user to input the number of vertices.
    cout << "How many vertices? ";
    cin >> vertices;
    
    Graph graph(vertices);
    
    graph.setLabels();
    
    string edgeInput;
    while (true) {
        cout << "Define an edge by listing a pair of vertices (e.g. A B) or -1 to stop: ";
        getline(cin >> ws, edgeInput);
        
        if (edgeInput == "-1") break;

        // Split the input into two vertices
        stringstream ss(edgeInput);
        string vertex1, vertex2;
        ss >> vertex1 >> vertex2;
        
        if (vertex1 == "-1" || vertex2 == "-1") break;
        graph.addEdge(vertex1, vertex2);
    }
    
    graph.listEdges();
    
    return 0;
}

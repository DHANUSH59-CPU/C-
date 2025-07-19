#include <iostream>
#include <vector>
#include <sstream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix, int n) {
    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row to get 90-degree rotation
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    cin.ignore(); // Clear the newline character after cin

    vector<vector<int>> matrix(n, vector<int>(n)); // 2D vector for matrix

    cout << "Enter the matrix row-wise (as space-separated numbers):\n";
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line); // Read the entire row as a string
        stringstream ss(line); // Convert string to stream
        for (int j = 0; j < n; j++) {
            ss >> matrix[i][j]; // Extract integers and store in matrix
        }
    }

    // Rotate the matrix 90 degrees clockwise
    rotateMatrix(matrix, n);

    // Print the rotated matrix
    cout << "\nRotated Matrix:\n";
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

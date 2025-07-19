#include <iostream>
#include <vector>

using namespace std;

// Function to print 2D vector
void printVector(const vector<vector<int>> &matr) {
    for (const auto &row : matr) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> bookings = {
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}
    };

    int len = bookings.size();
    int cols = 5;  // Adjusted columns based on the highest booking range

    // Initialize matrix with enough columns
    vector<vector<int>> matr(len, vector<int>(cols, 0));

    // Populate matrix
    for (int i = 0; i < len; i++) {
        for (int j = bookings[i][0] - 1; j <= bookings[i][1] - 1; j++) {
            matr[i][j] = bookings[i][2];
        }
    }

    // Print the matrix
    cout << "Final 2D Vector:" << endl;
    printVector(matr);

    return 0;
}

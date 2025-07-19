#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); // To clear the newline character left in the input buffer

    vector<string> s(n); // Correctly initializing the vector

    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, s[i]); // Read the full line
    }

    cout << "\nYou entered:\n";
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }

    return 0;
}

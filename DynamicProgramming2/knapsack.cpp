#include <iostream>
#include <vector>
#include <sstream> // for stringstream
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(vector<int> w , vector<int> val , int idx , int W){
    if(idx == w.size()){
        return 0;
    }

    // Similar to house robber

    if(dp[idx][W] != -1) return dp[idx][W];
    int ans = INT_MIN;
    // not pick
    ans = max(ans , f(w, val, idx + 1, W));
    // pick
    if(w[idx] <= W){
        ans = max(ans, val[idx] + f(w , val, idx + 1, W - w[idx]));
    }

    return dp[idx][W] = ans;
}

int fbu(vector<int> w , vector<int> val , int idx , int W){
    // if(idx == w.size()){
    //     return 0;
    // }
    int n = w.size();
    for(int i = n -1; i >= 0; i--){
        for(int j = 0; j <= W; j++){
            int ans = INT_MIN;
            // not pick
            ans = max(ans , dp[i + 1][j]);
            // pick
            if(w[i] <= j){
                ans = max(ans , val[i] + dp[i + 1][j - w[i]]);
          }
          dp[i][j] = ans;
          
        }
    }
    return dp[0][W];

}

vector<int> parseLineToInts(const string& line) {
    vector<int> result;
    stringstream ss(line);
    int number;
    while (ss >> number) {
        result.push_back(number);
    }
    return result;
}

int main() {
    int n, W;
    cin >> n >> W;
    cin.ignore(); // clear the newline character after cin

    string weightsLine, valuesLine;
    getline(cin, weightsLine);
    getline(cin, valuesLine);

    vector<int> weights = parseLineToInts(weightsLine);
    vector<int> values = parseLineToInts(valuesLine);

    dp.clear();
    dp.resize(n + 1, vector<int>(W + 1, -1));
    // dp.clear();
    // dp.resize(n + 1, vector<int>(W + 1, 0));  // Bottom-up

    // int maxProfit = knapsackRec(weights, values, n, W);
    // cout << maxProfit << endl;

    cout << f(weights,values ,0 , W);

    return 0;
}

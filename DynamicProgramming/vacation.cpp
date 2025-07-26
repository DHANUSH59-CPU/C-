#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int n;
    // cout<<"Enter the number of days : ";
    cin >> n;
    vector< vector<int>> dp(n, vector<int>(3,0));
    
    // base case
    int a,b,c;
    cin >> a >>b >>c;
    dp[0][0] = a;
    dp[0][1] = b;
    
    dp[0][2] = c;
    
    for(int i = 1; i < n; i++){
        // Input of hapinessn for ith day
        cin >> a >> b >> c;
        // for column a
        dp[i][0] = a + max(dp[i-1][1] , dp[i-1][2]);
        // for column b
        dp[i][1] = b + max(dp[i-1][0] , dp[i-1][2]);
        // for column c
        dp[i][2] = c + max(dp[i-1][1],dp[i-1][0]);
    }

    int ans = max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    cout << ans;
}
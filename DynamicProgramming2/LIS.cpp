#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

vector<int> nums;
vector<int> dp;

int f(int i){

    if(i == 0) return 1;

    int mx = INT_MIN;
    for(int j = 0; j <= i - 1; j++){
        if(nums[j] < nums[i]){
            mx = max(mx, f(j));
        }
    }
    if(mx == INT_MIN) return 1;
    return 1 + mx;
}

int main(){
    string s;
    cout << "Enter the array : ";
    getline(cin, s);

    stringstream ss(s);
     vector<int> v;

     int x;
    
     while(ss >> x){
        v.push_back(x);
     }
     nums.clear();
     nums = v;

     int ans = INT_MIN;

     dp.clear();
     dp.resize(100005, -1);

     // The below is for top-down aproach

    //  for(int i = 0; i < nums.size(); i++){
    //     ans = max(ans, f(i));
    //  }
    //  cout <<  ans;
    dp[0] = 1;
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j <= i - 1; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        if(dp[i] == -1) dp[i] = 1;
        ans = max(ans, dp[i]);
    }

    cout << ans;

     
}
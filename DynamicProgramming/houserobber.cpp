#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int f(vector<int> arr, int idx){
    if(idx == arr.size() - 1) return 0;
    if(idx ==  arr.size() - 2) return max(arr[idx],arr[idx+1]);

    if(dp[idx] != -1) return dp[idx];
    
    return dp[idx] = max(arr[idx] + f(arr,idx + 2), 0 + f(arr,idx + 1));
}

int fbu(vector<int> arr){
    int n = arr.size();

    dp.clear();
    dp.resize(1000005,INT_MIN);

    dp[n - 1] = arr[n-1];
    dp[n - 2] = max(arr[n - 1],arr[n - 2]);
    for(int i = n - 3; i >= 0; i--){
        dp[i] = max(arr[i] + dp[i + 2] , 0 + dp[i + 1]);
    }
    return dp[0];
}

int main(){
    string s;
    cout<<"Enter the Array : ";
    getline(cin,s);
    stringstream ss(s);
    int x;
    // dp.resize(100005,-1); Turn this on for bottom up approach
    vector<int> arr;
    while(ss >> x){
        arr.push_back(x);
    }

    // cout<<f(arr,0);
    cout << fbu(arr);
}
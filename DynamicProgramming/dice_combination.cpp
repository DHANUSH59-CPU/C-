#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int f(int t){
    if(t == 0) return 1; // Every time the Target becomes 0 in the tree, it is a way
    int sum = 0;
    for(int i = 1; i <= 6; i++){
        if(t - i < 0) break;
        sum += f(t - i);
    }
    return sum;
}

vector<int> dp;

int ftd(int t){ // here t represents the target.
    if(t == 0) return 1;
    if(dp[t] != -1) return dp[t];
    int sum = 0;
    for(int i = 1;i <= 6; i++){
        if(t - i < 0) break;
        sum += ftd(t - i);
    }
    return dp[t] = sum;
}

int fbu(int n){
    // if(n == 0) return 1;
    dp[0] = 1;

    for(int k = 1; k <= n; k++){ // To find the value of n we need all values less then n so IM using k -> n
        int sum = 0;
        for(int i = 1; i <= 6; i++){
            if(k - i < 0) break;
            sum += dp[k - i];
        }
        dp[k] = sum;
    }
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the target : ";
    cin >> n;
    dp.clear();
    dp.resize(n + 1,-1);
    cout << fbu(n);
}

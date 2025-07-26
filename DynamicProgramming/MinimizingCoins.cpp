#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>
using namespace std;


vector<int> coins;

int f(int n){
    if(n == 0) return 0;
    int result = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(n - coins[i] < 0) continue;
        result = min(result, f(n - coins[i]));
    }
    return 1 + result;
}

vector<int> dp;

int ftd(int n){
    if(n == 0) return 0;
    if(dp[n] != -2) return dp[n];
    int result = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(n - coins[i] < 0) continue;
        result = min(result, ftd(n - coins[i]));
    }
    if(result == INT_MAX) return dp[n] = INT_MAX;
    return dp[n] = 1 + result;
}

int main(){
    string s;
    cout<<"Enter the coins : ";
    getline(cin,s);
    coins.clear();
    int x;
    stringstream ss(s);
    while(ss >> x){
        coins.push_back(x);
    }
    dp.clear();
    dp.resize(1000005,-2);
    int n;
    cout<<"Enter the target : ";
    cin >> n;
    int ans = ftd(n);
    if(ans == INT_MAX) cout<<"-1";
    else cout<<ans;
}
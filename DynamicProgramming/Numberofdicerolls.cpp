#include<iostream>
#include<bits/stdc++.h>
using namespace std;

                // LeetCode 1155

int f(int n,int k,int t){
    if(t == 0 && n == 0) return 1;
    if(n == 0) return 0;
    int sum = 0;
    for(int i = 1; i<=k; i++){
        if(t - i < 0) continue;
        sum += f(n-1,k,t-i);
    }
    return sum;
}

vector<vector<int>> dp;

int ftd(int n, int k, int t){
    if(t == 0 && n == 0) return 1;
    if(n == 0) return 0;
    int sum = 0;
    if(dp[n][t] != -1) return dp[n][t];
    for(int i = 1; i <=6 ; i++){
        if(t - i < 0 ) continue;
        sum += ftd(n-1, k, t - i);
    }
    return dp[n][t] = sum;
}


int main(){
    int n;
    cout<<"Enter the number of dices : ";
    cin >> n;
    int k;
    cout<<"Enter faces in the dice : ";
    cin >> k;
    int t;
    cout<<"Enter the target sum : ";
    cin >> t;
    dp.clear();
    dp.resize(n + 1,vector<int>(t + 1, -1));
    cout<<ftd(n,k,t);
}
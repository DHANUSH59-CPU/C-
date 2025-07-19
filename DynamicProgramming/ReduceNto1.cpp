#include<iostream>
#include<vector>
#include<vector>
using namespace std;
#include<bits/stdc++.h>
#define inf INT_MAX

int f(int n){
    if(n == 0) return 0;
    if(n == 2 || n == 3) return 1;

    return 1 + min({f(n-1), (n % 2) ? f(n / 2) : inf, (n % 3) ? f(n / 3) : inf});
}

vector<int> dp;

int ftd(int n){
    if(n == 0) return 0;
    if(n == 2 || n == 3) return 1;

    if(dp[n] != -1) return dp[n];
    
    return dp[n] = 1 + min({f(n-1), (n % 2) ? f(n / 2) : inf, (n % 3) ? f(n / 3) : inf});
}

int main(){
    int n;
    cout<<"Enter the number : ";
    cin >> n;
    dp.clear();
    dp.resize(1000005,-1);
    cout<<ftd(n);
}
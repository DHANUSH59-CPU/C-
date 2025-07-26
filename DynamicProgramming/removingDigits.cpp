#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> Digits(int n){
    vector<int> d;
    while(n > 0){
        if(n % 10 != 0){
            d.push_back(n % 10);
        }
        n /= 10;
    }
    return d;
}


int f(int n){

    if(n == 0) return 0;
    if(n <= 9) return 1;
    
    vector<int> d = Digits(n);
    int results = INT_MAX;
    for(int i = 0; i < d.size(); i++){
        results = min(results, f(n - d[i]));
    }
    return 1 + results;
}

vector<int> dp;

int ftd(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;

    if(dp[n] != -1) return dp[n];

    vector<int> d = Digits(n);
    int result = INT_MAX; 
    for(int i = 0; i < d.size(); i++){
        result = min(result,ftd(n - d[i]));
    }
    return dp[n] = 1 + result;
}

int main(){
    int n;
    cout<<"Enter the number : ";
    cin >> n;
    dp.clear();
    dp.resize(1000005,-1);
    cout<<ftd(n);
}
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> ans;

void f(int i){
    if(i > n) return;
    if(i != 0)  ans.push_back(i);

    if(i != 0){
        for(int j = 0; j <= 9; j++){
            // ans.push_back(i);
            f(10 * i + j);
        }
    }
    else{
        for(int j = 1; j <= 9;j++){
            // ans.push_back(i);
            f(10 * i + j);
        }
    }
}

int main(){
    cout << "Enter the number : ";
    cin >> n;
    f(0);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] <<" ";
    }
}
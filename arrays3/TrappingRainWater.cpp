#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the array : ";
    string s;
    getline(cin,s);
    stringstream ss(s);
    int x;
    vector<int> h;

    while(ss >> x){
        h.push_back(x);
    }

    // for(auto ele : h){
    //     cout<<ele<<" ";
    // }

    int n = h.size();

    vector<int> prev(n);
    prev[0] = -1;
    int max = h[0];

    for(int i = 1; i < n; i++){
        prev[i] = max;
        if(max < h[i]){
            max = h[i];
        }
    }

    vector<int> nex(n);
    nex[n-1] = -1;
    max = h[n-1];

    for(int i = n-2; i >= 0; i--){
        nex[i] = max;
        if(max < h[i]){
            max = h[i];
        }
    }

    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        ans[i] = min(prev[i] , nex[i]);
    }

    int water = 0;

    for(int i = 0; i < n; i++){
        if(h[i] < ans[i]) water += (ans[i] - h[i]); 
    }


    // 0,1,0,2,1,0,1,3,2,1,2,1
    cout<<water;
}
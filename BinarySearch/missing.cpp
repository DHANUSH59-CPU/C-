#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements in array :";
    cin>>n;
    cout<<"Enter the array : ";
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
   
    int lo = 0;
    int hi = n-1;
    int ans = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(mid + 1 == v[mid]){
            lo = mid + 1;
        }
        else{
            ans = mid + 1;
            hi = mid - 1;
        }
    }

    cout<<ans;
}
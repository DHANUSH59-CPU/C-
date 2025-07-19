#include<iostream>
#include<string>
#include<sstream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    string s="Raghav is a teacher";
    stringstream ss(s);
    string temp;
    while(ss>>temp){
        cout<<temp<<endl;
    }
    string g="1 2 3 4";
    stringstream st(g);
    int x;
    vector<int> arr;
    while(st >> x){
        arr.push_back(x);
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
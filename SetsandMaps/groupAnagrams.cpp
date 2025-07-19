#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    cout<<"Enter the string : ";
    string s;
    getline(cin,s);
    stringstream ss(s);
    string x;
    vector<string> v;

    //"eat","tea","tan","ate","nat","bat"

    while(ss >> x){
        v.push_back(x);
    }
    //  cin.ignore();
    // for(auto ele : v){
    //     cout<<ele<<" ";
    // }

    unordered_map<string,vector<string>> m;

    for(auto ele : v){
        string key = ele;
        sort(key.begin(),key.end());
        m[key].push_back(ele);
    }

    vector<vector<string>> arr;

    for(auto ele : m){
        arr.push_back(ele.second);
    }

    for(auto ele : arr){
        for(auto ale : ele){
            cout<<ale<<" ";
        }
        cout<<endl;
    }
}
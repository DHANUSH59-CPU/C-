#include<bits/stdc++.h>
using namespace std;

void helper(int idx,vector<vector<int>> &ans,vector<int> &ds,vector<int> &fre,vector<int> &arr){
    ans.push_back(ds);
    for(int i=0;i<arr.size();i++){
        if(fre[i]==0){
            ds.push_back(arr[i]);
            fre[i]=1;
            helper(idx+1,ans,ds,fre,arr);
            ds.pop_back();
            fre[i]=0;
        }
    }
}

vector<vector<int>> permutation(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> fre;
    helper(0,ans,ds,fre,arr);
    return ans;
}

int main(){
    string s;
    cout<<"Enter the array elements :";
    getline(cin,s);
    stringstream ss(s);
    int x;
    vector<int> arr;
    while(ss >> x){
        arr.push_back(x);
    }

    vector<vector<int>> ans1=permutation(arr);
    for(int i=0;i<ans1.size();i++){
        for(int j=0;j<ans1[i].size();j++){
            cout<<ans1[i][j]<<" ";
        }
        cout<<endl;
    }
}
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]


#include<bits/stdc++.h>
using namespace std;

void findCombination(int idx,int target,vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(target==0){
            ans.push_back(ds);
            return;
    }

    for(int i=idx;i<arr.size();i++){
        if(i>idx && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        findCombination(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0,target,arr,ans,ds);
    return ans;
}

int main(){
    cout<<"Enter the array elements :";
    string s;
    getline(cin,s);
    stringstream ss(s);
    int x;
    vector<int> arr;
    while(ss >> x){
        arr.push_back(x);
    }
    cout<<"The entered array is :";
    for(auto ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    sort(arr.begin(),arr.end());

    int target;
    cout<<"Enter the target Element :";
    cin>>target;
    vector<vector<int>> ans = combinationSum2(arr,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
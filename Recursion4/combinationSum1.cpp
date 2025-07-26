// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.


// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []

#include<bits/stdc++.h>
using namespace std;

void findCombination(int idx,int target,vector<int> &arr, vector<vector<int>> &ans,vector<int> &ds){
    if(idx==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }

    if(arr[idx] <= target){
        ds.push_back(arr[idx]);
        findCombination(idx, target-arr[idx], arr, ans, ds);
        ds.pop_back();
    }
    findCombination(idx+1,target,arr,ans,ds);
}
vector<vector<int>> combination(vector<int> &arr,int target){
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0,target,arr,ans,ds);
    return ans;
}

int main(){
    cout<<"Enter the Array Elements in Spaced-Manner :";
    vector<int> arr;
    string s;
    getline(cin,s);
    stringstream ss(s);
    int x;
    while(ss >> x){
        arr.push_back(x);
    }

    cout<<"Entered vector is :"<<endl;
    for(auto ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    // vector<vector<int>>ans;
    // int n=arr.size()
    int target;
    cout<<"Enter the target :";
    cin>>target;
    vector<vector<int>> ans=combination(arr,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
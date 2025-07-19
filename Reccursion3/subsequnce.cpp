#include<bits/stdc++.h>
using namespace std;

void printL(int arr[],vector<int> &ans,int idx,int n){
    if(idx==n){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[idx]);
    printL(arr,ans,idx+1,n);
    ans.pop_back();
    printL(arr,ans,idx+1,n);
}

int main(){
    int n;
    cout<<"Enter the size of the Array :";
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements of array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Entered elements :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // now lets print subsequnce
    vector<int> ans;
    printL(arr,ans,0,n);
}
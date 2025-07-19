#include<iostream>
#include<vector>
using namespace std;

void subset(int arr[],int idx,int n,vector<int>ans){
    if(idx==n){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    subset(arr,idx+1,n,ans);
    ans.push_back(arr[idx]);
    subset(arr,idx+1,n,ans);
    // ans.push_back(arr[idx]);


}

int main(){
    int arr[]={1,2,3};
    vector<int> ans;
    int n=sizeof(arr)/sizeof(arr[0]);
    subset(arr,0,n,ans);
    // This pattern of taking some elements and removing some is known as this subset pattern
}
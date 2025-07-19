#include<bits/stdc++.h>
using namespace std;

bool printL(int arr[],vector<int> &ans,int idx,int n,int s,int sum){
    if(idx==n){
        if(s==sum){
            for(auto it : ans){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    ans.push_back(arr[idx]);
    s+=arr[idx];
    if(printL(arr,ans,idx+1,n,s,sum)==true){
        return true;
    }
    ans.pop_back();
    s-=arr[idx];
    if(printL(arr,ans,idx+1,n,s,sum)==true){
        return true;
    }
    return false;

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

    int sum;
    cout<<"Enter the target element :";
    cin>>sum;
    cout<<endl;
    vector<int> ans;
    printL(arr,ans,0,n,0,sum);
}
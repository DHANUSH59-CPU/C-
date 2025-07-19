#include<iostream>
using namespace std;

int main(){
    int arr[]={1,7,3,6,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    // formation of prefix sum
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    // now search for partition
    int idx=-1;
    for(int i=1;i<n;i++){
        if(2*arr[i]==arr[n-1]){
            idx=i;
            break;
        }
    }
    if(idx!=-1) cout<<"Yes the array can be partitioned at "<<idx<<endl;
    else cout<<"Array cannot be partitioned.";
}
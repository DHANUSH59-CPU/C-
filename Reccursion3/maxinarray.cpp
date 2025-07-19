#include<iostream>
using namespace std;

int maxelement(int arr[],int idx,int n){
    if(idx==n) return INT16_MIN;
    return max(arr[idx],maxelement(arr,idx+1,n));
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=maxelement(arr,0,n);
    cout<<max;
}
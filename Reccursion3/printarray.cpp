#include<iostream>
using namespace std;

void display(int arr[],int idx,int n){
    if(idx==n) return;
    cout<<arr[idx]<<" ";
    display(arr,idx+1,n);
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,0,n);
}
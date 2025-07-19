#include<bits/stdc++.h>
using namespace std;

int printL(int arr[],int idx,int n,int s,int sum){
    if(idx == n){
        if(s == sum){
            return 1;
        }
        else{
            return 0;
        }
    }
    s += arr[idx];
    int left = printL(arr,idx+1,n,s,sum);
    s -= arr[idx];
    int right = printL(arr,idx+1,n,s,sum);
    return left + right;
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
    int noOfways=printL(arr,0,n,0,sum);
    cout<<"The number of subsequnces :"<<noOfways;
}
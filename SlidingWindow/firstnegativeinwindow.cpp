#include<iostream>
using namespace std;

int main(){
    int arr[]={2,-3,4,4,-7,-1,4,-2,6,9,0,-1,7,46,-4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int p=-1;
    int ans[n-k+1];
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            p=i;
            break;
        }
    }

    if(p==-1) ans[0]=1;
    else ans[0]=arr[p];
    // now apply sliding window
    int i=1;
    int j=k;
    while(j<n){
        if(p>=i) ans[i]=arr[p];
        else{ // i is greater then p means pointer p which was pointing to negative number is not included in the new window
            p=-1;
            for(int x=i;x<j;x++){
                if(arr[x]<0){
                    p=x;
                    break;
                }
            }
            if(p!=-1) ans[i]=arr[p];
            else ans[i]=1;
        }
        i++;
        j++;
    }
    // now print the ans array
    for(int i=0;i<n-k+1;i++){
        cout<<ans[i]<<" ";
    }
}
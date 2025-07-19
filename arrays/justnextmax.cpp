        // was asked in college

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans[n];
    for(int i=0;i<n;i++){
        int max=arr[i];
        for(int j=i+1;j<n;j++){
            if(max<arr[j]){
                max=arr[j];
                break;
            }
        }
        if(max==arr[i]){
            ans[i]=-1;
        }
        else{
            ans[i]=max;
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
}
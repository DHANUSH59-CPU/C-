#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={7,1,2,5,3,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int maxsum=INT16_MIN;
    int maxIdx=0;
    int prevsum=0;
    for(int i=0;i<k;i++){ // T.C O(k)
        prevsum+=arr[i];
    }
    maxsum=prevsum;
    int i=1;
    int j=k;// sliding window
    while(j<n){ // T.C O(n-k)
        int currsum=prevsum+arr[j]-arr[i-1];
        if(maxsum<currsum){
            maxsum=currsum;
            maxIdx=i;
        }
        prevsum=currsum;
        i++;
        j++;
    }
    // T.C =(n-k+1)*k
    // timecomplexity =o(k*n)
    cout<<maxsum<<endl;
    cout<<maxIdx;
}
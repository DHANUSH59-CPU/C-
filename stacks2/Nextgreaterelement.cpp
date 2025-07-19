#include<bits/stdc++.h>
using  namespace std;

int main(){
    string s;
    cout<<"Enter the array elements :";
    getline(cin,s);
    stringstream ss(s);
    int x;
    vector<int> arr;
    while(ss >> x){
        arr.push_back(x);
    }

    // brute force
    // T.C is o(n^2) and S.C is o(n) 
    // int n=arr.size();
    // vector<int> ans(n);
    // for(int i=0;i<n;i++){ 
    //     ans[i]=-1;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[j]>arr[i]){
    //             ans[i]=arr[j];
    //             break;
    //         }
    //     }
    // }
    // cout<<"The answer array is :";
    // for(auto ele : ans){
    //     cout<<ele<<" ";
    // }


    


    // Using stack
    // Pop ans Push method
    int n = arr.size();
    vector<int> nge(n);
    nge[n-1]=-1;
    stack <int> st;
    st.push(arr[n-1]);

    //Pop
    for(int i=n-2;i>=0;i--){
        while(st.size() > 0 && st.top() < arr[i]){
            st.pop();
        }
        
        // ans update
        if(st.size()==0) nge[i]=-1;
        else nge[i]=st.top();

        // push the current idx element
        st.push(arr[i]);
    }

    for(auto ele : nge){
        cout<<ele<<" ";
    }
}
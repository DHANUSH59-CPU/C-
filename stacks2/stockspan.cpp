#include<bits/stdc++.h>
using namespace std;

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
    int n=arr.size();

    // lets find previous greatest elements index 
    cout<<"The entered elements are :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    vector<int> pgI(n);
    pgI[0]=-1;
    stack<int> st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.size()==0) pgI[i]=-1;
        else{
            pgI[i]=st.top();
        }
        st.push(i);
    }

    for(int i=0;i<n;i++){
        pgI[i]=i-pgI[i];
    }

    cout<<"The stock span is :";
    for(int i=0;i<n;i++){
        cout<<pgI[i]<<" ";
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Entered the elements of array :";
    getline(cin,s);
    stringstream ss(s);
    int x;
    vector<int> arr;
    while(ss >> x){
        arr.push_back(x);
    }
    int n=arr.size();
    stack<int> st;

    st.push(arr[0]);
    vector<int> pge(n);
    pge[0]=-1;
    for(int i=1;i<n;i++){
        while(st.size() > 0 && st.top() <= arr[i]){
            st.pop();
        }

        // ans pushing
       if(st.size()==0){
        pge[i]=-1;
    }
    else{
        pge[i]=st.top();
    }

        // current ele pushing
        st.push(arr[i]);
    }
    for(auto ele : pge){
        cout<<ele<<" ";
    }
}
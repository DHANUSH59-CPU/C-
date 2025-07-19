#include<bits/stdc++.h>
using namespace std;

bool prove(string s,stack<char> st){
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(s[i]);
        else{ // s[i]==')'
            if(st.size()==0){
                return false;
            }
            st.pop();
        }
    }
    return true;
}

int main(){
    string s;
    cout<<"Enter the Bracket string :";
    getline(cin,s);

    stack<char> st;
    cout<<prove(s,st);
}
#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
        vector<int> v(150,1000);
        for(int i=0;i<s.size();i++){
            int idx=(int)s[i];
            if(v[idx]==1000) v[idx]=s[i]-t[i];
            else if(v[idx]!=(s[i]-t[i])) return false;
        }
        // make the array empty for t's perceptive
        for(int i=0;i<150;i++){
            v[i]=1000;
        }
         for(int i=0;i<s.size();i++){
            int idx=(int)t[i];
            if(v[idx]==1000) v[idx]=t[i]-s[i];
            else if(v[idx]!=(t[i]-s[i])) return false;
        }
        return true; 
    }

int main(){
    string s;
    cout<<"Enter the string s : ";
    getline(cin,s);
    string t;
    cout<<"Enter the string t : ";
    getline(cin,t);
    cout<<isIsomorphic(s,t);
}
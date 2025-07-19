#include<iostream>
using namespace std;

void removechar(string ans,string original){
    if(original.length()==0){
        cout<<ans;
        return;
    }
    char ch=original[0];
    if(ch=='a') removechar(ans,original.substr(1));
    else removechar(ans+ch,original.substr(1));
}

int main(){
    // string s="dhanush";
    // string ans;
    // for(int i=0;i<s.length();i++){
    //     if(s[i]!='a') ans.push_back(s[i]);
    // }  
    // cout<<ans;

    // now using recursion
    string str="Dhanush is a god";
    string ans="";
    removechar(ans,str);
}
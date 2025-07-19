#include<iostream>
#include<vector>
using namespace std;

void storesubset(string ans,string original,vector<string>& v){
    if(original==""){
        v.push_back(ans);
        return;
    }


    char ch=original[0];
    storesubset(ans,original.substr(1),v);
    storesubset(ans+ch,original.substr(1),v);
}

int main(){
    string str="abc";
    string ans="";
    vector<string> v;
    storesubset(ans,str,v);
    for(auto ele:v){
        cout<<ele<<endl;
    }
}
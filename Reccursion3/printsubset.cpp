#include<iostream>
using namespace std;

void printsubset(string ans,string original){
    if(original==""){
        cout<<ans<<endl;
        return;
    }
    char ch=original[0];
    printsubset(ans+ch,original.substr(1));
    printsubset(ans,original.substr(1));
}
int main(){
    string str="abc";
    string ans="";
    printsubset(ans,str);
}
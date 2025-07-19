#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

string ans = "";

int f(string s1 , string s2, int i, int j, string output){

    if(output.size() > ans.size()) ans = output;

    if(i >= s1.size()) return 0;
    if(j >= s2.size()) return 0;


    if(s1[i] == s2[j]){
        return 1 + f(s1 , s1 , i + 1, j + 1, output + s1[i]);
    }
    else{
        return max(f(s1 , s2 , i + 1 , j , output) , f(s1 , s2 , i , j + 1 , output));
    }
}

int main(){
    string s1;
    cout<<"Enter the string : ";
    getline(cin,s1);
    string s2;
    s2 = s1;
    reverse(s2.begin(),s2.end());
    cout << f(s1 , s2 , 0 , 0 , "") <<endl;
    cout << ans;
}
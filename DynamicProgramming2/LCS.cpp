#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
string ans = "";
int f(string s1,string s2, int i ,int j , string output){
    if(output.size() > ans.size()) ans = output;
    if(i >= s1.length()) return 0;
    if(j >= s2.length()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        return dp[i][j] =  1 + f(s1 , s2 , i + 1 , j + 1 , output + s1[i]);
    }
    else{
        return dp[i][j] = max(f(s1 , s2 , i , j + 1 , output) , f(s1 , s2 , i + 1 , j , output));
    }
}

int main(){
    string s1;
    cout<<"Enter the string 1 : ";
    getline(cin,s1);
    string s2;
    cout << "Enter the string 2 :";
    getline(cin,s2);
    dp.clear();
    dp.resize(1005 , vector<int>(1005,-1));
    cout << f(s1,s2,0,0,"")<<endl;
    cout<<ans;
}


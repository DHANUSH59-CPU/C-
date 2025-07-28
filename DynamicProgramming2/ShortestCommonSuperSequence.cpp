#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1;
    cout << "Enter the 1st string : ";
    getline(cin, s1);
    string s2;
    cout << "Enter the 2nd string : ";
    getline(cin, s2);

    vector<vector<int>> dp;
    dp.resize(1005, vector<int>(1005, 0));

    int n = s1.size();
    int m = s2.size();

    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    // cout << dp[0][0];

    int i = 0;
        int j = 0;
        string scs = "";

        while(i < n && j < m){
            if(s1[i] == s2[j]){
                scs += s1[i];
                i++;
                j++;
            }
            else if(dp[i + 1][j] > dp[i][j + 1]){
                scs += s1[i];
                i++;
            }
            else{
                scs += s2[j];
                j++;
            }
        }

        while(i < n) scs += s1[i++];
        while(j < m) scs += s2[j++];

        cout<< scs;


}
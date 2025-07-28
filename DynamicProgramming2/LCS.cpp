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


    // Below is T-D approch
    // cout << f(s1,s2,0,0,"")<<endl;

    // cout<<ans;


    // Lets implement Bottom-Up approch

    int n = s1.size();
    int m = s2.size();

    dp.clear();
    dp.resize(1005, vector<int>(1005, 0));

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

    // Lets print the string

    int i = 0;
    int j = 0;

    string lcs = "";

    while(i < n && j < m){
        if(s1[i] == s2[j]){
            lcs += s1[i];
            i++;
            j++;
        }
        else if(dp[i + 1][j] > dp[i][j + 1]){
            i++;
        }
        else{
            j++;
        }
    }

    cout << lcs;
}


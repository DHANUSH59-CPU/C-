
#include<bits/stdc++.h>
using namespace std;

int main(){
    // we are gng to solve this using pre-computation

    vector<bool> dp(1000005, -1);

    int l , k;
    cin >> l >> k;
    dp[1] = 1;
    dp[l] = 1;
    dp[k] = 1;

    for(int i = 2; i <= 1000000; i++){
        dp[i] = !(dp[i - 1] && ((i - k >= 1) ? dp[k - 1] : 1) && ((i - k >= 1) ? dp[i - l] : 1))
    }

    for(int i = 0; i < m; i++){
        int n;
        cin >> n;
        if(dp[n] == 1){
            // n -> winning state
            cout<<"A";
        }
        else{
            // n -> loosing state
            cout<<"B";
        }
    }

}
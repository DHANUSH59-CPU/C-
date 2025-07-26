#include<bits/stdc++.h>
using namespace std;
vector<int> h;
vector<int> dp;
int f(int i, int k){
    if(i >= h.size()) return INT_MAX;
    
    if(i == h.size() - 1) return 0;

    if(dp[i] != -1) return dp[i];

    int ans = INT_MAX;
    for(int j = 1; j <= k; j++){
        if(i + j >= h.size()) break;
        ans = min(ans, abs(h[i] - h[i + j]) + f(i + j , k));
    }

    return dp[i] = ans;
}

int fbu(int k ){
    int n = h.size();
    dp.resize(1000005 , INT_MAX);
    // base condition
    dp[n-1] = 0;
    
    for(int i = n-2; i >= 0; i--){
        for(int j = 1; j <= k; j++){ // This approach is used in knap sac also
            if(i + j > n - 1) break;
            dp[i] = min(dp[i],  abs(h[i] - h[i + j]) + dp[i + j]);
        }
    }
    return dp[0];
}

int main(){
    string s;
    cout<<"Enter the array elements in space saparated manner : ";
    getline(cin, s);
    stringstream ss(s);
    int x;
    while(ss >> x){
        h.push_back( x );
    }
    // dp.resize(1000005, -1);
    int k;
    cout<<"Enter the value of k : ";
    cin >> k;
    // cout<<f(0 , k);
    cout << fbu(k);

}
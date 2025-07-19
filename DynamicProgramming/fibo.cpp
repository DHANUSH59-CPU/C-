#include<bits/stdc++.h>
using namespace std;

vector<int> dp(35,-1);
int fibo(int n){
    if(n == 0 || n == 1) return n;

    if(dp[n] != -1) return dp[n];
    return dp[n] = fibo(n-1) + fibo(n-2);
}

int fibobu(int n){
    vector<int> ans(n);
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2; i < n; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n-1];
}

int fibobasic(int n){
    int a = 1;
    int b = 1;
    int c = 1;
    for(int i = 2; i < n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cout << "Enter the number : ";
    cin >> n;
    // dp.clear();
    cout << fibobasic(n);
}
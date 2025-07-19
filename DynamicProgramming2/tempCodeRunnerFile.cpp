#include<bits/stdc++.h>
#include<vector>
# define ll long long int
using namespace std;

vector<vector<ll>> dp(105,vector<ll> (1000005 , -1));

ll f(vector<int> &wts, vector<int> &val, int idx , int W){
    if(idx == wts.size()) return 0;

    ll ans = INT_MIN;

    if(dp
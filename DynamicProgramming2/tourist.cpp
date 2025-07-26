#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll m, n;
char mat[105][105];

ll dp[105][105][105];

ll f(int i, int j, int x, int y){

    if(i > n || j > m || x > n || y > m || mat[i][j] == '#' || mat[x][y] == '#') return 0;

    if(i == n && j == m){  //  // is the tourist 1 already at n, m (i + j) == (n + m)
        return (mat[i][j] == '*'); //  Im not adding for tourist 2, because when tourist 1 reaches the end point, tourist 2 will also reach bez im ading 1 for both
    }

     if(dp[i][j][x] != -1) return dp[i][j][x];

    ll result = INT_MIN;
    

    // We could have write all this 4 lines below inside a single max({}), but it would be complicated thats why we simply use INT_MIN;
    result = max(result, f(i + 1, j, x + 1, y));
    result = max(result, f(i, j + 1, x, y + 1));
    result = max(result, f(i + 1, j, x, y + 1));
    result = max(result, f(i, j + 1, x + 1, y));

    result += (mat[i][j] == '*');
    result += (mat[x][y] == '*');

    // remove duplicates

    if(i == x && j == y && mat[i][j] == '*') result--;

    return dp[i][j][x] =result;
   
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
         memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> mat[i][j];
            }
        }
        cout << f(1, 1, 1, 1) << endl;
    }
}
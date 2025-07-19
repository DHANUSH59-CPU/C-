#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout<<"Enter the number of columns and rows : ";
    getline(cin,s);
    stringstream ss(s);
    int n,m;
    ss >> n >> m;
    int minr = 0;
    int minc = 0;
    int maxr = n - 1;
    int maxc = m - 1;

    vector<vector<char>> ans(n, vector<char>(m));

    // Optional: Just to confirm
    cout << "Matrix initialized with " << n << " rows and " << m << " columns.\n";

    char ch = 'X';

    while(minr <= maxr && minc <= maxc){
        for(int j = minc; j <= maxc; j++){
            ans[minr][j] = ch;
        }
        minr++;

        if(minr > maxr || minc > maxc) break;

        for(int i = minr; i <= maxr; i++){
            ans[i][maxc] = ch;
        }
        maxc--;

        if(minr > maxr || minc > maxc) break;

        for(int j = maxc; j >= minc; j--){
            ans[maxr][j] = ch;
        }
        maxr--;

        if(minr > maxr || minc > maxc) break;

        for(int i = maxr; i >= minr; i--){
            ans[i][minc] = ch;
        }

        minc++;

        if(minr > maxr || minc > maxc) break;

        if(ch == 'X'){
            ch = '0';
        }

        else{
            ch = 'X';
        }
    }

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

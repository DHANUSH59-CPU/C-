#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


void setmatrix(vector<vector<int>> & ans){
    unordered_set<int> rows, cols;

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            if(ans[i][j] == 0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for(int row : rows){
        for(int j = 0; j < ans[0].size(); j++){
            ans[row][j] = 0;
        }
    }

    for(int col : cols){
        for(int i = 0; i < ans.size(); i++){
            ans[i][col] = 0;
        }
    }
}




int main(){
    int n;
    cout<<"Enter the number of rows : ";
    cin >> n;
    int m;
    cout<<"Enter the number of columns : ";
    cin >> m;
    vector<vector<int>> ans(n,vector<int> (m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ans[i][j];
        }
    }

    cout<<endl;

     setmatrix(ans);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j]<<" ";
        }
        cout<<endl;
    } 
}

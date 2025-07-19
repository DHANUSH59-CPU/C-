#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int ans = 0;

int main(){
    int n;
    cout<<"Enter the number of rows : ";
    cin >> n;
    int m;
    cout<<"Enter the number of  colmuns : ";
    cin >> m;
    cin.ignore();

    vector<vector<int>> dp( n, vector<int>(m));
    cout << "Enter the matrix row-wise (as space-separated numbers):\n";
    for(int i = 0; i < n; i++){
        string s;
        getline(cin,s);
        stringstream ss(s);
        for(int j = 0; j < m; j++){
            ss >> dp[i][j];
        }
    }

    cout<<endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dp[i][j] == 0) dp[i][j] = 0;
            else dp[i][j] += dp[i-1][j];
        }
    }

    cout<<endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int>pre(m);
    vector<int>nex(m);

    for(int i = 0; i < n; i++){
        stack<int>st;
         
        // Lets find pre smaller element
        pre[0] = -1;
        st.push(0);
        for(int j = 1; j < m; j++){

            while(st.size() > 0 && dp[i][st.top()] >= dp[i][j]){
                st.pop();
            }
            if(st.size() == 0) pre[j] = -1;
            else pre[j] = st.top();

            st.push(j);
        }

        // Lets find next smaller element

        stack<int> st1;
        nex[m-1] = m;
        st1.push(m - 1);
        for(int j = m - 2; j >=0 ; j--){
            while(st1.size() > 0 && dp[i][st1.top()] >= dp[i][j]){
                st1.pop();
            }
            if(st1.size() == 0) nex[j] = m;
            else nex[j] = st1.top();

            st1.push(j);
        }


        for(int k = 0; k < m; k++){
            int area = dp[i][k] * (nex[k] - pre[k] - 1);
            ans = max(ans , area);
        }
    }

    cout<<ans;

}
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> prices;

int f(int i, int k, bool on){
    if(i == prices.size()) return 0;

    int ans = INT_MIN;
    // not include
    ans = f(i + 1, k, on); // avoid

    // not avoid
    if(on){
        ans = max(ans, prices[i] + f(i + 1, k - 1, false));
    }
    else{
        if(k > 0){
            ans = max(ans, f(i + 1, k, true) - prices[i]);
        }
    }
    return ans;
}

int main(){
    string s;
    cout << "Enter the prices separated by commas: ";
    getline(cin, s);
    
    // Replace commas with spaces for stringstream to parse
    replace(s.begin(), s.end(), ',', ' ');
    
    stringstream ss(s);
    int x;
    while(ss >> x){
        prices.push_back(x);
    }
    
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    cout << f(0, k, false);
    return 0;
}
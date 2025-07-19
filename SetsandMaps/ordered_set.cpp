#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    // It is going to store in ascending order No matter in which order we insert

    for(auto ele : s){
        cout<<ele<<" ";
    }
    
}
#include<iostream>
using namespace std;

int mazepath(int er,int ec,string s){
    if(er < 1 || ec < 1) return 0;
    if(er == 1 && ec == 1){
        cout << s << endl;
        return 1;
    }
    int rightways = mazepath(er, ec - 1, s + 'R');
    int leftways = mazepath(er - 1, ec, s + 'D');
    return rightways + leftways;
}

int main(){
    int er;
    cout<<"Enter the ending row :";
    cin>>er;
    int ec;
    cout<<"Enter the ending column :";
    cin>>ec;
    int totalnumberofWays=mazepath(er,ec,"");
    cout<<totalnumberofWays;
}
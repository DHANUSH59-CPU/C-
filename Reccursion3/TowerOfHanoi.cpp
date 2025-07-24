#include<iostream>
using namespace std;

void TowerOfHanoi(int n,char a,char b,char c) { // where a is source and b is helper and c is destination
    if(n == 0) return;
    TowerOfHanoi(n-1, a, c, b);
    cout << a << " -> " << c << endl;
    TowerOfHanoi(n-1 , b, a, c);

}
int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    TowerOfHanoi(n,'A','B','C');
}
#include <iostream>
using namespace std;
int solve(int n,int m){
    if (n>=m) return n-m;
    if (m%2) return 1+solve(n,m+1);
    return 1+solve(n,m/2); 
}
int main() {
    int n,m; cin>>n>>m;
    cout<<solve(n,m);
    return 0;
}
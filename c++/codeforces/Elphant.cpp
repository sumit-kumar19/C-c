#include<bits/stdc++.h>
using namespace std ;

void solve(){
    int n;
    cin>>n;
    int step =n/5;
    n%=5;
    if(n>=1)
    step++;
   
    cout<<step;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
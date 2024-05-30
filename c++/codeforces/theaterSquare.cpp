#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n,m,a;
    cin>>n>>m>>a;
    long long x =n/a;
    long long y =m/a;
    if(n%a!=0)
        x++;
    if(m%a!=0)
        y++;

    std::cout<<x*y<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
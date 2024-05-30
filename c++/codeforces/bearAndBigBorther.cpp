#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;
    cin>>a>>b;
    int c=0;
    while(a<=b){
        a*=3;
        b*=2;
        c++;
    }
    cout<<c;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
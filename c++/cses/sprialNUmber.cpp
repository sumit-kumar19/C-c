#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll t;
    cin >> t;
    while(t--){
    ll x,y;
    cin>>y>>x;
    if(y>x){
        ll m = (y-1) * (y -1);
        ll tmp = 0;
        if(y%2!=0){
            tmp = x;
        } else{
            tmp = 2 * y -x;
        }
        cout << tmp+m << "\n";
    } else {
        ll m = (x-1) * (x -1);
        ll tmp = 0;
        if(x%2==0){
            tmp = y;
        } else{
            tmp = 2 * x - y;
        }
        cout << tmp+m << "\n";
        }

    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
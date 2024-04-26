#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll idx, vector<ll> &arr, ll sum1, ll sum2, ll N) {
   
}
int main() {
      ll N;
    cin >> N;
    vector<ll> arr(N);
    for (ll i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    ll ans = solve(0, arr, 0, 0, N);
    cout << ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,x;
  int flag=0;
  cin>>n>>x;
  ll arr[n];
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  map <ll,ll> m;
  for(ll i=0;i<n;i++){
    if(m.count(x-arr[i])){
      cout << i+1  << " " << m[x-arr[i]]<< "\n";
      return 0;
    }
    m[arr[i]] = i + 1;
  }
  cout<<"IMPOSSIBLE";
}

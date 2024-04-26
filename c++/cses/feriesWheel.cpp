#include<bits/stdc++.h>
using namespace std ;
#define ll long long

void solve(){
  int n;
  cin>>n;
  vector<ll> res(n);
  ll x;
  cin>>x;
  for(int i=0;i<n;i++){
    cin>>res[i];
  }
  sort(res.begin(),res.end());
  int left=0,right=n-1;
  ll sum=0;
  ll count=0;
  while(left<=right){
     sum=res[left]+res[right];
     if(sum<=x){
     left++;
  }
    count++;
    right--;
  }
  cout<<count;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}


#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int main(){
    unsigned long int n;
    cin>>n;
    int mod=1000000007;
    if(n==0||n==1)cout<<n;
    else{
    if(n==2)cout<<1;
    else{
    ll f=0,s=1;
    ll th=f+s;
    n=n%mod;
    for(ll i=3;i<=n;i++){
     f=s;
     s=th;
     th=(f+s);
    }
    cout<<th%mod;
    }}
}
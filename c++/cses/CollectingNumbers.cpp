#include<bits/stdc++.h>
using namespace std;
 void solve(){
      int n;
      cin>>n;
      int arr[n];
      int arr1[n+1];
      arr1[0]=0;
      for(int i=0; i<n;i++){
        cin>>arr[i];
      }
      for(int i=0; i<n;i++){
      arr1[arr[i]]=i;
      }
      int count = 1;
      for(int i=0; i<n;i++){
      if(arr1[i+1]<arr1[i])
      count++;
      }
      cout<<count<<endl;
 }
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
 }
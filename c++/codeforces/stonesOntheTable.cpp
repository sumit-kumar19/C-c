#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count =0 ;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1])
        count++;
    }
    cout << count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
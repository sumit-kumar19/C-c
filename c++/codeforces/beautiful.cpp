#include<bits/stdc++.h>
using namespace std;

void solve(){
     int a,b;
     int out=-1;
     int t;
     for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>t;
            if(t==1){
                a=i;
                b=j;
                break;
            }
        }
     }
     cout<<abs(2-a)+abs(2-b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
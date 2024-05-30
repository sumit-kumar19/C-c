#include<bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin>>t;
    vector<pair<int,int> > pa;
    while(t--){
        int a,b;
        cin>>a>>b;
         pa.push_back(make_pair(a,1));
         pa.push_back(make_pair(b,-1));
    }
    sort(pa.begin(), pa.end());
    int max=0;
    int even=0;
    for(auto it : pa){
        even+=it.second;
        if(even>max){
            max=even;
        }
    }
    cout<<max<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int lc=0,uc=0;
    for(char a:s){
        if(a>='a'&&a<='z') lc++;
        else 
        uc++;
    }
    if(uc > lc){
		for(auto &c : s){
			c = toupper(c);
		}
	} else {
		for(auto &c : s){
			c = tolower(c);
		}
	}
    cout<<s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
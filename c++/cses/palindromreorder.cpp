#include<bits/stdc++.h>
using namespace std;
void solve(){
    	string s;
	cin>>s;
	int f[26] = {};
	int n = s.size();
	string o(n,' ');
	for(int i=0;i<n;i++){
		f[s[i]-'A']++;
	}
	int odd = 0;
	for(int i=0;i<26;i++){
		if(f[i]%2!=0)odd++;
	}
	if(odd > 1){
		cout<<"NO SOLUTION";
		return;
	}
	int l = 0,r=n-1;
	for(int i=0;i<n;i++){
		if(f[s[i]-'A'] % 2 == 1){
			o[n / 2] = s[i];
            f[s[i] - 'A'] --;
        }
        while (f[s[i] - 'A'] > 0) {
            o[l++] = o[r--] = s[i];
            f[s[i] - 'A'] -= 2;
        }
    }
	cout<<o;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
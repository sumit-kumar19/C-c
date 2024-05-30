#include<bits/stdc++.h>
using namespace std;
 
bool isVowel(char s){

}

void solve(){
    string s;
    cin>>s;
    string out;
    for(auto  x : s){
       char t=tolower(x);
        if(t=='a'||t=='e'||t=='i'||t=='o'||t=='u'||t=='y')
        continue;
        out.push_back('.');
        out.push_back(t);
    }
    cout << out;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
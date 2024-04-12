#include <bits/stdc++.h>
#define ll long long
using namespace std;

int c = 0;
map<string,int> m;

void permutate(string a,int l,int r){
    c++;
    if(l==r)
    {
        if(m[a] == 0) m[a]++;
    } 
    else 
    {
        for (int i = l; i <=r; i++)
        {
            swap(a[l],a[i]);
            permutate(a,l+1,r);
            swap(a[l],a[i]);
        }
    }
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    sort(begin(s),end(s));
    permutate(s,0,n-1);

    set<string>st;
    for (auto s : m)
    {
        st.insert(s.first);
        // cout << s.first <<"\n";
    }
                cout<<st.size()<<"\n";
                cout << m.size() << "\n";

    //for(auto i:st)cout<<i<<"\n";

        // cout << c << "\n";
        // 

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
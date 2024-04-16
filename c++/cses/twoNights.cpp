#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int mod = 1000000007;
    for (long long i = 1; i <= n; i++)
    {
        unsigned long long mul = ((long long)(i * i) * (i * i - 1)) / 2 - (4 * (i - 1) * (i - 2));
        cout << (long long)mul << "\n";
    }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum % 2 == 0)
    {
        cout << "YES"
             << "\n";
        vector<ll> set1, set2;
        long long mid = sum / 2;
        for (int i = n; i >= 1; i--)
        {
            if (i <= mid)
            {
                set1.push_back(i);
                mid -= i;
            }
            else
                set2.push_back(i);
        }
        cout << set1.size() << "\n";
        for (int i = 0; i < (int)set1.size(); i++)
        {
            cout << set1[i] << " ";
        }
        cout << "\n";
        cout << set2.size() << "\n";
        for (int i = 0; i < (int)set2.size(); i++)
        {
            cout << set2[i] << " ";
        }
    }
    else
        cout << "NO";
}
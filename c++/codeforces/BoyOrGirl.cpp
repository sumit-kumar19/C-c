#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a;
    cin >> a;
    int arr[26] = {0};
    for (auto x : a)
    {
        arr[x - 'a']++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0)
            count++;
    }
    if (count % 2 == 0)
        cout << "CHAT WITH HER!";

    else
        cout << "IGNORE HIM!";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
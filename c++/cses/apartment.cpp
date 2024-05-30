#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int maxScore = 0;

    unordered_map<char, int> mp;
    for (auto x : letters)
        mp[x]++;
    for (int i = 0; i < words.size(); i++)
    {
        // string temp=words[i];
        unordered_map<char, int> temp = mp;
        int sum = 0;
        for (int j = i; j < words.size(); j++)
        {
            int temp_sum = 0;
            for (char it : words[j])
            {
                if (temp[it] == 0)
                {
                    temp_sum = 0;
                    break;
                }
                temp_sum += score[it - 'a'];
                cout << it << ' ' << score[it-'a'] << ' ';
                temp[it]--;
            }
            sum += temp_sum;
            cout << endl;
            cout << sum << ' ' << endl;
        }
        maxScore = max(maxScore, sum);
    }
    cout << "maxScore: " << maxScore << endl;
}

void solve1(){
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int maxScore = 0;
    unordered_map<char
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    solve1();
}
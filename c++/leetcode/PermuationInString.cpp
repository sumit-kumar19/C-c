#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkfreqency(int arr1[], int arr2[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2)
    {
        if (s2.length() < s1.length())
            return false;
        int arr1[26] = {0};
        for (auto x : s1)
        {
            arr1[x - 'a'];
        }
        int end = 0;
        int start = 0;
        int arr2[26] = {0};
        while (start != s2.length())
        {
            arr2[s2[start] - 'a']++;
            if (start - end + 1 == s1.length())
            {
                if (checkfreqency(arr1, arr2))
                    return true;
                arr2[s2[end] - 'a']--;
                end++;
                start++;
            }
            else if (start - end + 1 < s1.length())
            {
                start++;
            }
        }
        return false;
    }
};
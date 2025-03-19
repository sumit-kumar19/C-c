class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char, set<char>> mp;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            mp[ch] = {ch};
        }
        for (int i = 0;i<s1.size(); i++) {
            char a = s1[i],b=s2[i];
            set<char> mergedSet;
            mergedSet.insert(mp[a].begin(),mp[a].end());
            mergedSet.insert(mp[b].begin(),mp[b].end());
            char minChar=*mergedSet.begin();
            for (char ch:mergedSet) {
                mp[ch]=mergedSet;
            }
        }
        string res = "";
        for (char ch:baseStr) {
            res+=*mp[ch].begin(); 
        }
        return res;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        string str = "";
        string ans = "";
        int it = 0;
        while (it < len) {
            str = "";
            while (s[it] != ' ' && it < len) {
                str += s[it];
                it++;
            }
            while (s[it] == ' ' && it < len) {
                it++;
            }
            if (!str.empty()) {
                if (ans.empty())
                    ans += str;
                else
                    ans = str + ' ' + ans;
            }
        }
        return ans;
    }
};
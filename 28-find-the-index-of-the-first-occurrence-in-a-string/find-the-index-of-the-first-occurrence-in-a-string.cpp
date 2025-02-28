class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> pre(m, 0);
        int j = 0;
        for (int i = 1; i < m; i++) {
            if (needle[i] == needle[j]) {
                pre[i] = ++j;
            } else {
                if (j == 0) {
                    pre[i] = j;
                } else {
                    while (j > 0) {
                        if (needle[i] == needle[j]) {
                            break;
                        }
                        j = pre[j - 1];
                    }
                    i--;
                }
            }
        }

        j = 0;
        for (int i = 0; i < n; i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = pre[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
                if (j == m) {
                    return i - j + 1;
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> smp(26,0), pmp(26,0);
        vector<int> result;
        
        if(p.size() > s.size())
            return result;
        
        int start = 0, end = 0;
        while(end < p.size()){
            pmp[p[end] - 'a']++;
            smp[s[end] - 'a']++;
            end++;
        }
        end--;
        while(end < s.size()){
            if(pmp == smp) result.push_back(start);

            end++;
            
            if(end != s.size()){
                smp[s[start] - 'a'] --;
                smp[s[end] - 'a'] ++;
                
            }
            start++;
        }
        return result;
    }
};
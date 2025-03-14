class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>m;
        for(auto it:s) m[it]++;
         int even=INT_MAX;     
         int odd=0;              
        for(auto it:m){      
            if(it.second%2==0) even=min(even,it.second);
            else odd=max(odd,it.second);
        }
        return odd-even;
    }
};
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
         unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
        }

        int s;
        for(auto a: mp){
            if(a.second == (nums.size()/2)){
                s=a.first;
            }
        }
        return s;
    }
};
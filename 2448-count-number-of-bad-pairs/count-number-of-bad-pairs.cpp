class Solution {
    typedef  long long  ll;
public:
    long long countBadPairs(vector<int>& nums) {
       ll total = (ll) nums.size() * (nums.size()-1)/2;

       unordered_map <int,ll> diffCount;

           auto processPair = [&](int i) {
            total -= diffCount[nums[i] - i];
            diffCount[nums[i] - i]++;
        };
        
        for (int i = 0; i < nums.size(); i++) {
            processPair(i);
        }
        return total;

    }
};
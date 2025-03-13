class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), range = 0, count = 0;
        vector<int> cnt(n + 1, 0);
        for (int i=0;i<n;i++) {
            while (range+cnt[i]<nums[i]) {
                if (count == queries.size()) return -1;
                int left = queries[count][0], right=queries[count][1];
                int val = queries[count][2];
                count++;
                
                if (right < i) continue;
                cnt[max(left, i)] += val;
                cnt[right + 1] -= val;
            }
            range += cnt[i];
        }
        return count;
    }
};
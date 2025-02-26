class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int maxsum=0,minsum=0,presum=0,ans=0;

        for (int n : nums) {
            presum+=n;
            ans=max(ans,max(abs(presum - minsum), abs(presum - maxsum)));

            if (presum>=0) maxsum = max(maxsum, presum);
            else minsum = min(minsum, presum);
        }
        return ans;
    }
};
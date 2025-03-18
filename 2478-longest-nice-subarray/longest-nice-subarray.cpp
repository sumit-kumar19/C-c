class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int count = 0,s = 0 ,maxLen= 0;  
        for (int end = 0; end < nums.size(); ++end) {
            while ((count&nums[end]) != 0) {
                count^=nums[s]; 
                s++;
            }
            count|=nums[end];
            maxLen=max(maxLen,end-s+1);
        }
        return maxLen;
    }
};
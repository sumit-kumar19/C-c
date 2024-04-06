class Solution {
public:
    int countHillValley(vector<int>& nums) {
       int n=nums.size();
        int l=nums[0],count=0;

        for(int i=1;i<n-1;i++){
            if(nums[i]>l && nums[i]>nums[i+1]){
                count++;
                l=nums[i];
            }
            else if(nums[i]<l && nums[i]<nums[i+1]){
                count++;
                l=nums[i];
            }
            else if(nums[i]!=nums[i+1]) l=nums[i];
        }
        return count; 
    }
};
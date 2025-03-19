class Solution {
public:
    int minOperations(vector<int>& nums) {
    int count =0 ;
    int it1=2;
    while(it1<nums.size()){
        if(nums[it1-2]==0){
            nums[it1]=!nums[it1];
            nums[it1-2]=!nums[it1-2];
            nums[it1-1]=!nums[it1-1];
            count++;}
            it1++;
    }
    if (any_of(nums.begin(), nums.end(), [](int val) {return val==0;})) {
        return -1;
        }
        return count;
    
    }
};
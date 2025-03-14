 bool compare(int a,int b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string str="";
        sort(nums.begin(),nums.end(),compare);
        if(nums[0]==0)
        return "0";
        for(auto num:nums)
        str+=to_string(num);
        return str;
        
    }
};
#include<bits/stdc++.h>
using namspace std ;
    int threeSumClosest(vector<int>& nums, int target) {
         if(nums.size()<3)
        return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
         int min=1e6;
        for(int i=0;i<nums.size()-2;++i){
          int    l=i+1,r=nums.size()-1;
                while(l<r){
                    int sum=nums[i]+nums[l]+nums[r];
                    if(sum==target)
                    return target;
                    else if(sum>target)
                    r--;
                    else 
                    l++;
                    if(abs(sum-target)<abs(min-target))
                    min=sum;
                    }
                }return min;
    }
    int main(){
        int 
    }

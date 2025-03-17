class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int maxelement = *max_element(nums.begin(),nums.end());

        vector<int> count(maxelement+1,0);
    for_each(nums.begin(), nums.end(), [&](int num) { count[num]++; });
        // for(int i=0;i<=maxelement ; i++ ) {
        //     if(count[i]%2!=0)
        //     return false;
      if (any_of(count.begin(), count.end(), [](int val) {return val%2!=0;})) {
        return false;
        }

        return true;
    }
};
class Solution {
public:
bool helper(vector<int>&candies, int &m, long long &k){
    long long ans = 0;
    for(int i=0;i<candies.size();++i){
        ans+=candies[i]/m;
    }
    return ans>=k;
}
    int maximumCandies(vector<int>& candies, long long k) {
      int left = 1, right = *max_element(candies.begin(),candies.end());

      while(left<=right){
        int m = left + (right-left)/2;
        if(helper(candies,m,k)) left =m+1;
        else right = m-1;
      }
    return right;
    }
};
class Solution {
public:
    int canrob(vector<int>&a, int mid){
        int lasthouse = -2;
        int count= 0 ;
        for(int i = 0 ;i<a.size();i++){
            if(a[i]<=mid && lasthouse!=i-1){
                lasthouse=i;
                count++;
            }
        }
        return count;
    }
    int minCapability(vector<int>& a, int k) {
        int n =a.size(), ans= - 1;    
        int lo=*min_element(a.begin(),a.end());
        int hi=*max_element(a.begin(),a.end());
        while(hi>=lo){
            int mid=(hi+lo)/2;
            if(canrob(a,mid)>=k){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};
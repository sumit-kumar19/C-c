class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1000000007;
        int oddCount=0,evenCount=0;
        int sum=0;
        int totalarray=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0) 
            {
                totalarray=(totalarray+oddCount)%mod;
                evenCount++;
            }else{
                totalarray=(totalarray+evenCount+1)%mod;
                oddCount++;
            }
        }
        return totalarray;

    }
};
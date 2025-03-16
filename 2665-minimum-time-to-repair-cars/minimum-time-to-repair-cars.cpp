class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left =1,right= (long long)*min_element(ranks.begin(), ranks.end())*cars*cars;
        
        auto can_repair_all = [&](long long time) {
            long long tcr=0;
            for (int it :ranks) {
                tcr+=sqrt(time/it);
                if (tcr>=cars) return true;
            }
            return false;
        };
        
        while (left<right) {
            long long mid=left+(right-left) / 2; 
            if (can_repair_all(mid))
                right=mid;
            else
                left=mid+1;  
        }
        return left;
    }
};

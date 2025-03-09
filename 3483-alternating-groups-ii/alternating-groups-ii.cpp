class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res=0,size=1;
        int n = colors.size(),prev=colors[0];
        for(int i=0;i<n+k-1;i++){
            if(prev == colors[i%n]){
                size = 1;
            }
            else{
                size++;
                if(size >= k){
                    res++;
                }
            }
            prev = colors[i%n];
        }
        return res;
    }
};
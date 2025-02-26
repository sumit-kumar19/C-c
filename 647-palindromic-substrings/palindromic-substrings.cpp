class Solution {
public:
    int countSubstrings(string str) {
        int n = str.size();
        int left,right,res=0;
        for(int i=0;i<n;i++){
            left =  right = i;
            while(left>=0 && right<n){
                if(str[left]==str[right]) res++;
                else break;
                left--;
                right++;
            }
            if(i==0) continue;
            left = i-1, right = i;
            while(left>=0 && right<n){
                if(str[left]==str[right]) res++;
                else break;
                left--;
                right++;
            }
        }
        return res;
    }
};
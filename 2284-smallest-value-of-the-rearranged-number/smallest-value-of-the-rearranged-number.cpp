class Solution {
public:
    long long smallestNumber(long long num) {
        if(abs(num)<10) return num; 
        int isneg=0;
        if(num<0) isneg=1;
        vector<int> count(10,0);
        long long temp = abs(num);
        while(temp!=0){
        count[temp%10]++;
        temp/=10;
        }
        long long ans=0;
        if(isneg) {
              for (int i=9;i>=0;i--) {
                while(count[i]>0) {
                    ans=ans*10+i;
                    count[i]--;
                }
            }
            return -ans;
        }

        else {
            int ii=1;
            while(ii<10){
                if(count[ii]>0) break;
                ii++;
            }
            ans=ii;
            count[ii]--;
            while(count[0]>0){            
                ans*=10;
                count[0]--;
            }
            for(int i=0;i<10;i++){
                while(count[i]>0){
                    ans=ans*10+i;
                    count[i]--;
                }
            }
            
        }
        return ans;
    }
};

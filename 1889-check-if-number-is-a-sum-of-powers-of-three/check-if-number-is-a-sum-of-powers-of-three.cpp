class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(1){
            if(n==1) return true;
            if(n%3==2) 
               return false;
            n/=3;
        }
        return false;
    }
};
class Solution {
    typedef long long ll;
public:
    int findNthDigit(int n) {
        if(n<10 )
        return n;
       ll base=9;
       ll dig=1;

       while((ll)n  > (base*dig))
       {
        n-=(base*dig);
        base*=10;
        dig+=1;

       }
       ll num = pow(10,(dig-1))+(n-1)/dig;
    int idx=(n-1)%dig;
    return to_string(num)[idx]-'0';


    }
};
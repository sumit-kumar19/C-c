class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size()-1;
        while( n>=0){
            if(num[n]=='1'||num[n]=='3'||num[n]=='5'||num[n]=='7'||num[n]=='9')
            return num;
            else num.pop_back();
            n--;
        }
        return num;
    }
};
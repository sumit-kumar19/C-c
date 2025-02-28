class Solution {
public:
    int maxDepth(string s) {
        int counter=0,maxcounter=0;
        for(char it:s){
                if(it=='(')
                counter++;
                if(it==')')
                counter--;
                maxcounter=max(maxcounter,counter);
        }
        return maxcounter;
    }
};
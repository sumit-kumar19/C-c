class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int bcount=0,mini=INT_MAX;
        for( int i=0;i<=blocks.size()-k;i++){
            int wcount=0;
            for(int j=i;j<i+k;j++){
                if(blocks[j]=='W')
                wcount++;
            }
            mini=min(mini,wcount);
        }
        return mini;
    }
};
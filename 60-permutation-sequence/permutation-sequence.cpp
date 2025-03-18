class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> st;
        int temp = k-1;
        int f=1 ;
        for(int  i = 1 ; i < n ; i++ ) {
            f*=i;
            st.push_back(i);
        }
        st.push_back(n);
        string res = "";
        while(1){
            res+=to_string(st[temp/f]);
            st.erase(st.begin()+temp/f);
            if(st.size()==0) break;

            temp = temp % f;
            f=f/st.size();
        }
        return res;
    }
};
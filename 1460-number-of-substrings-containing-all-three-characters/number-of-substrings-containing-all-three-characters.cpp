class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> arr(3,0);
        int count=0,start =0 ,end=0;
        int n =s.size();
      for (int end = 0; end < n; end++) {
            arr[s[end] - 'a']++; 

            while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0) {
                count += (n - end);  
                arr[s[start] - 'a']--; 
                start++;
            }
        }

       return count ; 
    }
};
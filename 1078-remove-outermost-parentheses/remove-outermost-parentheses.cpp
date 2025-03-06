class Solution {
public:
    string removeOuterParentheses(string s) {
        // int i =0,j=0;
        // string str="";

        // while(j<s.size()){
        //         if(i==0&&s[j]=='('){
        //             i++;j++;
        //         }
        //         else{
        //             if(s[j]=='('){
        //                 i++;
                       
        //             }
        //             else{
        //                 i--;

        //             }
        //              j++;
        //                 str+=s[j];
        //         }
        //         if(i==1&& s[j]==')'){
        //             i--;
        //             j++;
        //         }

        // }
        // return str;

        int out=0;
        string str="";
        for(int i=0;i<s.size();i++){
          if(s[i]=='('){
            if(out>0)
            str+=s[i];

            out++;
          }
          else if(s[i]==')'){
            out--;
            if(out>0)
            str+=s[i];

          }
        }

        return str;
    }
};
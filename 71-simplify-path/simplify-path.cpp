class Solution {
public:
    string simplifyPath(string path) {
        string str = "";
        vector<string> store; 
        string temp;
        
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') { 
                if (!temp.empty()) {  
                    store.push_back(temp);
                    temp = "";
                }
            } else temp += path[i];
            
        }
        
        if (!temp.empty()) store.push_back(temp);
    

        vector<string> st; 
        for (auto &s : store) {
            if (s == "." || s.empty()) 
                continue;
            else if (s == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(s);
            }
        }

        string result = "/";
        for (int i = 0; i < st.size(); i++) {
            result += st[i];
            if (i != st.size() - 1) result += "/";
        }
        
        return result;
    }
};

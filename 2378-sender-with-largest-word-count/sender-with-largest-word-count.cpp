class Solution {
public:
int count(string s) {
    int count=1;
    for(int i =0;i<s.size();i++){
            if(s[i]==' ')
            count++;
    }
    return count;
}
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
         vector<pair<string,int>>v;
        for(int i=0;i<messages.size();i++){
            v.push_back({senders[i],count(messages[i])});
        }
        unordered_map<string,int>m;
        for(int i=0;i<v.size();i++){
            m[v[i].first]+=v[i].second;
        }
        string ans="";
        int temp=0;
        for(auto it:m){
            if(temp<it.second){
                ans=it.first;
                temp=it.second;
            }
            else if(temp==it.second){
                if(ans<it.first)
                ans=it.first;
            }
        }
        return ans;
    }
};
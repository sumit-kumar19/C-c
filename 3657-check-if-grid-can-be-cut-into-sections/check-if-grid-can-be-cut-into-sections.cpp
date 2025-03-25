using pp = pair<long long,long long>;
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& v) {
         long long m=v.size();
         vector<pp>v1,v2;
         for(auto it:v){
            v1.push_back({it[0],it[2]});
            v2.push_back({it[1],it[3]});
         }
         sort(v1.begin(), v1.end());
         sort(v2.begin(), v2.end());
         long long ct1=0, ct2=0, r1=INT_MIN,r2=INT_MIN;
        for(int i=0;i<m;i++){
            if(i>0){
                if(v1[i].first>=r1)
                 ct1++;
                if(v2[i].first>=r2)ct2++;
            }
            r1=max(r1,v1[i].second);
            r2=max(r2,v2[i].second);
        }
        if(ct1>=2||ct2>=2)return true;
        
        return false;

    }
};
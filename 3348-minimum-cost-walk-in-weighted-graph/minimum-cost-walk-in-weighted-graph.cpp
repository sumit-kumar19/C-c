class Solution {
    vector<int>par,size;
    unordered_map<int,int>mp1,mp2;
    int src,k;
    void dfs(vector<pair<int,int>>adj[],int i,vector<int>&vis){
       mp1[i]=src;
       vis[i]=1;
       for(auto it:adj[i]){
        if(!vis[it.first]){
            
            dfs(adj,it.first,vis);
        }
        if(k==-1)k=it.second;
        else k=k&it.second;
       }  
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
       vector<pair<int,int>>adj[n];
       map<vector<int>,int>st;
       for(int i=0;i<edges.size();i++){
        if(edges[i][0]>edges[i][1])swap(edges[i][0],edges[i][1]);
       }

       for(auto it:edges){
         if(st.find({it[0],it[1]})==st.end())st[{it[0],it[1]}]=it[2];
         else st[{it[0],it[1]}]&=it[2];
       }


       for(auto it:edges){
        int wt=st[{it[0],it[1]}];
        adj[it[0]].push_back({it[1],wt});
        adj[it[1]].push_back({it[0],wt});
       }


       vector<int>ans,vis(n,0);
       for(int i=0;i<n;i++){
         if(!vis[i]){
            k=-1,src=i;
            dfs(adj,i,vis);
            mp2[src]=k;

         }
       }

       
        for(auto it:query){
          int p=-1;
          if(mp1[it[0]]==mp1[it[1]]){
            p=mp2[mp1[it[0]]];
          }
          if(it[0]==it[1])p=0;
          ans.push_back(p);
       } 
        
       
        return ans;
    }
};
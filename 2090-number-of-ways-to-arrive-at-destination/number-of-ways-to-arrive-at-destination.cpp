class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto& r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }    
        vector<long long>dist(n,1e18),totalWays(n,0);
        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,greater<>>pq;
        int MOD=1e9+7;
        dist[0]=0;
        totalWays[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop();
            if(d>dist[u])continue;
            for(auto&[v,w]:adj[u]){
                if(dist[v]>d+w){
                    dist[v]=d+w;
                    totalWays[v]=totalWays[u];
                    pq.push({dist[v],v});
                }else if(dist[v]==d+w){
                    totalWays[v]=(totalWays[v]+totalWays[u])%MOD;
                }
            }
        }
        return totalWays[n-1];
    }
};
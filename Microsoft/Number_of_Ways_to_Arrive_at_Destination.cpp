class Solution {
public:
    int mod = 1e9 + 7;
    vector<long long> dist;
    vector<long long> dp;
    void dijkstra(vector<vector<pair<int, int>>> &g, int src){
        set<pair<long long, int>> s; // dist and node
        dist[src] = 0;
        s.insert({0, src}); 
        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            long long distTillNow = it->first;
            s.erase(it);
            for(auto nbrPair : g[node]){
                int nbr = nbrPair.first;
                long long currEdge = nbrPair.second;
                if(distTillNow + currEdge < dist[nbr]){
                    auto f = s.find({dist[nbr],nbr});
					if(f!=s.end()) s.erase(f);
					dist[nbr] = distTillNow + currEdge;
					s.insert({dist[nbr],nbr});
                    dp[nbr] = dp[node] % mod;
                }
                else if(distTillNow + currEdge == dist[nbr]){
                    dp[nbr] = (dp[nbr] + dp[node]) % mod;
                }
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        for(auto &i: roads){
            g[i[0]].push_back({i[1], i[2]});
            g[i[1]].push_back({i[0], i[2]});
        }
        dist.resize(n, LLONG_MAX);
        dp.resize(n, 0L);
        dp[0] = 1;
        dijkstra(g, 0);
        return dp[n-1] % mod;
    }
};

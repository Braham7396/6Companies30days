class Solution {
public:
    bool cycle(vector<vector<int>> &g, vector<int> &seen, int idx){
        if(seen[idx] == 1) return true;
        if(seen[idx] == 2) return false;
        
        seen[idx] = 1;
        for(auto &i: g[idx])
            if(cycle(g, seen, i)) return true;
        
        seen[idx] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        vector<int> seen(n, 0);
        for(int i=0;i<pre.size();i++)
            g[pre[i][1]].push_back(pre[i][0]);
        for(int i=0;i<n;i++)
            if(cycle(g, seen, i)) return false;
        
        return true;
    }
};

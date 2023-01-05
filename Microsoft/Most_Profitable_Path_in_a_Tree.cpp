class Solution {
public:
    int dfs(vector<vector<int>> &tree, int idx, vector<int> &seen, vector<int> &amount, int ctr){
        if(idx == 0) return 1;
        if(seen[idx]) return 0;
        seen[idx] = 1;
        int ans = 0;
        for(auto &i: tree[idx]){
            ans = dfs(tree, i, seen, amount, ctr+1);
            if(ans != 0) {
                ans = ans + 1;
                if(ctr < ans) amount[idx] = 0;
                else if(ctr == ans) amount[idx] /= 2;
                return ans;
            }
        }
        return 0;
    }
    int dfs2(vector<vector<int>> &tree,vector<int> &seen, vector<int> &amount, int idx){
        seen[idx] = 1;
        if(tree[idx].size() == 1 && idx != 0){
            return amount[idx];
        }
        int ans = INT_MIN;
        for(auto &i: tree[idx]){
            if(seen[i] == 0)
                ans = max(ans, amount[idx] + dfs2(tree, seen, amount, i));
        }
        return ans;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> tree(n);
        vector<int> seen(n, 0);
        for(auto &i: edges)
            tree[i[0]].push_back(i[1]), tree[i[1]].push_back(i[0]);
        dfs(tree, bob, seen, amount, 1);
        seen.assign(n, 0);
        return dfs2(tree, seen, amount, 0);
    }
};

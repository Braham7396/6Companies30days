class Solution {
public:
    int ans = 0, N;
    bool possible(vector<vector<int>>& st, vector<int> &ver){
        for(int i=0;i<N;i++){
            if(ver[i] == 0) continue;
            for(int j=0;j<N;j++) if(st[i][j] != 2 && (st[i][j] ^ ver[j]) == 1) return false;
        }
        return true;
    }
    void solve(vector<vector<int>>& st, vector<int> &ver, int idx, int good){
        if(idx == N){
            if(possible(st, ver)) ans = max(ans, good);
            return;
        }
        ver[idx] = 0;
        solve(st, ver, idx+1, good);
        ver[idx] = 1;
        solve(st, ver, idx+1, good+1);
        ver[idx] = 2;
    }
    int maximumGood(vector<vector<int>>& st) {
        N = st.size();
        vector<int> ver(N, 2);
        solve(st, ver, 0, 0);
        return ans;
    }
};

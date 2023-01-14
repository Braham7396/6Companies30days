class Solution {
public:
    bool possible(int sz, int x, int y, int n, int m){
        if(y + sz - 1 < m and y - sz + 1 >= 0 and x + 2*sz - 2 < n) 
            return true;
        return false;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> s;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> rd(n+m-1), ld(n+m-1);
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(rd[j+i].size() == 0) rd[j+i].push_back(grid[i][j]);
                else rd[j+i].push_back(rd[j+i].back() + grid[i][j]);
                if(ld[n-(i-j)-1].size() == 0) ld[n-(i-j)-1].push_back(grid[i][j]);
                else ld[n-(i-j)-1].push_back(ld[n-(i-j)-1].back() + grid[i][j]);
            }
        }
        for(int sz = 1; sz <= (min(n, m) + 1) / 2; sz++){
            for(int j=0;j<m;j++){
                for(int i=0;i<n;i++){
                    if(!possible(sz, i, j, n, m)) continue;
                    int res = 0;
                    // RD1
                    res += rd[j+i][min(j, n-i-1)];
                    if(min(j, n-i-1) - sz >= 0)
                        res -= rd[j+i][min(j, n-i-1) - sz];
                    // RD2
                    res += rd[j+(i+2*sz-2)][min(j, n-(i+2*sz-2)-1)+sz-1];
                    if(min(j, n-(i+2*sz-2)-1)-1 >= 0)
                        res -= rd[j+(i+2*sz-2)][min(j, n-(i+2*sz-2)-1)-1];
                    // LD1
                    res += ld[n-(i-j)-1][min(j, i)+sz-1];
                    if(min(j, i)-1 >= 0)
                        res -= ld[n-(i-j)-1][min(j, i)-1];
                    // LD2
                    res += ld[n-((i+2*sz-2)-j)-1][min(j,(i+2*sz-2))];
                    if(min(j,(i+2*sz-2))-sz >= 0)
                        res -= ld[n-((i+2*sz-2)-j)-1][min(j,(i+2*sz-2))-sz];
                    //
                    if(sz == 1) res /= 4;
                    else res -= (grid[i][j]+grid[i+2*sz-2][j]+grid[i+sz-1][j+sz-1]+grid[i+sz-1][j-sz+1]);
                    cout << res << endl;
                    if(s.size() < 3) s.insert(res);
                    else if(res > *s.begin() and s.find(res) == s.end()) s.erase(s.begin()), s.insert(res);
                }
            }
        }
        vector<int> ans;
        for(auto &i: s)
            ans.push_back(i);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

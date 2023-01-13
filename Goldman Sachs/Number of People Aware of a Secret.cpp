class Solution {
public:
    int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<map<pair<int, int>, int>> vmp(n+1);
        vmp[1][{delay, forget}] = 1;
        for(int i=2;i<=n;i++){
            for(auto &j: vmp[i-1]){
                if(j.first.second == 1) continue;
                if(j.first.first <= 1) {
                    vmp[i][{0, j.first.second - 1}] += j.second;
                    vmp[i][{delay, forget}] += j.second;
                    vmp[i][{0, j.first.second - 1}] %= mod;
                    vmp[i][{delay, forget}] %= mod;
                }
                else {
                    vmp[i][{j.first.first - 1, j.first.second - 1}] += j.second;
                    vmp[i][{j.first.first - 1, j.first.second - 1}] %= mod;
                }
            }
        }
        int ans = 0;
        for(auto &i: vmp[n])
            ans = (i.second + ans) % mod;
        
        return ans;
    }
};

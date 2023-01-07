class Solution {
public:
    bool is_empty(vector<deque<int>> &mp){
        for(auto &i: mp) if(i.size() == 0) return true;
        return false;
    }
    int numberOfSubstrings(string s) {
        int n = s.size(), ans = 0;
        vector<deque<int>> mp(3);
        for(int i=0;i<n;i++) mp[s[i]-'a'].push_back(i);
        for(int i=0;i<n;i++){
            if(is_empty(mp)) break;
            int idx_max = max({mp[0][0], mp[1][0], mp[2][0]});
            int idx_min = min({mp[0][0], mp[1][0], mp[2][0]});
            ans += n - idx_max;
            mp[s[idx_min] - 'a'].pop_front();
        }
        return ans;
    }
};

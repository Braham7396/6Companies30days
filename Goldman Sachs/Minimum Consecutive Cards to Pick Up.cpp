class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(mp[cards[i]] == 0) mp[cards[i]] = i+1;
            else{
                ans = min(ans, i+1-mp[cards[i]]+1);
                mp[cards[i]] = i+1;
            }  
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

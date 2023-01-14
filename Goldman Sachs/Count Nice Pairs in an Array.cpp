class Solution {
public:
    int mod = 1e9+7;
    int rev(int x){
        int res = 0;
        while(x){
            res *= 10;
            res += x - (x/10)*10;
            x /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long int ans = 0;
        for(auto &i: nums)
            i = i - rev(i), mp[i]++;
        for(auto &i: mp) {
            long long int x = i.second;
            if(x < 2) continue;
            ans += (x * (x - 1) / 2);
            ans %= mod;
        }
        int res = ans;
        return res;
    }
};

class Solution {
public:
    long long int p = 31, mod = 1e9+7;
    string longestPrefix(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        int max_len = 0;
        long long int lh = 0, rh = 0, pwr=1;
        
        while(l < n-1){
            lh = (lh + (s[l]-'a'+1)*pwr + mod) % mod;
            rh = (rh*p + s[r]-'a'+1 + mod) % mod;
            if(lh == rh) max_len = l+1;
            pwr = (pwr * p) % mod;
            l++, r--;
        }
        return s.substr(0, max_len);
    }
};

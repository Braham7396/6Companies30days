class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), res = -1, last = -1;
        vector<int> dp(n, 1), trace(n, -1);
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--)
                if(nums[i] % nums[j] == 0 and dp[j] >= dp[i]) dp[i]=dp[j]+1, trace[i]=j;
            if(dp[i] > res) res = dp[i], last = i;
        }
        vector<int> ans;
        while(last != -1){
            ans.push_back(nums[last]);
            last = trace[last];
        }
        return ans;
    }
};

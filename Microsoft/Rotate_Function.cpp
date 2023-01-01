class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), prev = 0, sum = 0;
        for(int i=0;i<n;i++) prev += i * nums[i], sum += nums[i];
        int res = prev;
        for(int i=n-1;i>=1;i--){
            res = max(res, prev + sum - n*nums[i]);
            prev = prev + sum - n*nums[i];
        }
        return res;
    }
};

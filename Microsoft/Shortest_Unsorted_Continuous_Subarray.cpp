class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), ans;
        int start = n-1, end = 0, prev = INT_MIN;
        // for Largest index not in range, end
        for(int i=0;i<n;i++){
            if(nums[i] < prev) end = i;
            prev = max(nums[i], prev);
        }
        // for smallest index not in range, start
        prev = INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(nums[i] > prev) start = i;
            prev = min(nums[i], prev);
        }
        (end > start) ? ans = end - start + 1: ans = 0;
        return ans;
    }
};

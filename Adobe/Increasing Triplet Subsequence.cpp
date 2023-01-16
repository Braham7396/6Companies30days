class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> res1(n, 0), res2(n, 0);
        int mn = nums[0], mx = nums[n-1];
        for(int i=1;i<n-1;i++){
            if(nums[i] > mn) res1[i] = 1;
            else if(nums[i] < mn) mn = nums[i];
        }
        for(int i=n-2;i>=1;i--){
            if(nums[i] < mx) res2[i] = 1;
            else if(nums[i] > mx) mx = nums[i];
        }
        for(int i=0;i<n;i++){
            if((res1[i] & res2[i])) return true;
        }
        return false;
    }
};

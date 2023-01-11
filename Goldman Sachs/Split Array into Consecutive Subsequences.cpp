class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for(auto &i: nums) freq[i]++;
        for(auto &i: nums){
            if(!freq[i]) continue;
            if(need[i] > 0){
                need[i]--;
                freq[i]--;
                need[i+1]++;
            }
            else if(freq[i]>0 and freq[i+1]>0 and freq[i+2]>0){
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
                need[i+3]++;
            }
            else return false;
        }
        return true;
    }
};

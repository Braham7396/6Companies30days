class Solution {
public:
    int N, K;
    void add(vector<vector<int>> &res, vector<int>& arr, int idx, int sum){
        if((sum > N) or (sum == N and arr.size() < K) or (arr.size() > K)) return;
        if(sum == N and arr.size() == K){
            res.push_back(arr);
            return;
        }
        for(int i=idx;i<10;i++){
            if(sum + i <= N){
                arr.push_back(i);
                add(res, arr, i+1, sum + i);
                arr.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        N = n, K = k;
        vector<vector<int>> res;
        vector<int> arr;
        add(res, arr, 1, 0);
        return res;
    }
};

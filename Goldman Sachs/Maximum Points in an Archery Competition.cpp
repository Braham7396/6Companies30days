#include<bits/stdc++.h>
class Solution {
public:
    int max_ans = 0;
    vector<int> res;
    void solve(vector<int> &alice, vector<int> bob, int arrows, int idx, int sum){
        if(idx == 12 and arrows == 0 and sum > max_ans){
            max_ans = sum;
            for(auto i : bob) cout << i << " ";
            cout << endl;
            res = bob;
            return;
        }
        else if(idx == 12 and sum > max_ans){
            bob[0] += arrows;
            max_ans = sum;
            res = bob;
            return;
        }
        else if(idx == 12 and sum <= max_ans) return;
        
        if(arrows > alice[idx]){
            bob[idx] = alice[idx]+1;
            solve(alice, bob, arrows - alice[idx] - 1, idx + 1, sum + idx);
            bob[idx] = 0;
        }
        solve(alice, bob, arrows, idx + 1, sum);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bob(12);
        solve(aliceArrows, bob, numArrows, 0, 0);
        return res;
    }
};

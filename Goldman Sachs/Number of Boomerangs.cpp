class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& pts) {
        int ans = 0, n = pts.size();
        for(int i=0;i<n;i++){
            unordered_map<double, int> mp;
            for(int j=0;j<n;j++){
                double dist = sqrt(pow(pts[i][0]-pts[j][0], 2)+pow(pts[i][1]-pts[j][1], 2));
                mp[dist]++;
            }
            for(auto &i: mp){
                int x = i.second;
                ans += (x * (x - 1));
            }
        }
        return ans;
    }
};

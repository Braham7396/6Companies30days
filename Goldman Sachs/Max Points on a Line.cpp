class Solution {
public:
    int maxPoints(vector<vector<int>>& pts) {
        int res = 1, n = pts.size();
        int INF = 1e9;
        for(int i=0;i<n;i++){
            unordered_map<double, int> mp;
            for(int j=i+1;j<n;j++){
                if(pts[j][0] - pts[i][0] == 0) mp[INF]++;
                else{
                    double slope = double(pts[j][1] - pts[i][1]) / double(pts[j][0] - pts[i][0]);
                    mp[slope]++;
                }
            }
            for(auto &i: mp) res = max(res, i.second + 1);
        }
        return res;
    }
};

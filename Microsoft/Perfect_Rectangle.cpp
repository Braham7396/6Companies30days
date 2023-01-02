class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rec) {
        map<pair<int, int>, int> cnr;
        for(auto &i: rec){
          // Right Diagonal = +
          // Left Diagonal = -
            cnr[{i[0], i[1]}]++;
            cnr[{i[0], i[3]}]--;
            cnr[{i[2], i[1]}]--;
            cnr[{i[2], i[3]}]++;
        }
        int ctr = 0;
        for(auto &i: cnr){
            if(i.second != 0){
                if(abs(i.second) != 1) return false;
                ctr++;
            }
        }
        return ctr == 4;
    }
};

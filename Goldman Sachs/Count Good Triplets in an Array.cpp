struct fenwick {
    vector<int> fn;
    int n;
    fenwick(int _n){
        n = _n+1;
        fn.resize(n, 0);
    }
    void add(int x, int y){
        x++;
        while(x < n){
            fn[x] += y;
            x += (x & (-x));
        }
    }
    int sum(int x){
        x++;
        int ans = 0;
        while(x){
            ans += fn[x];
            x -= (x & (-x));
        }
        return ans;
    }
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0L;
        int n = nums1.size();
        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[nums2[i]] = i;
        fenwick tree(n);
        for(int i=0;i<n;i++){
            int index = idx[nums1[i]];
            tree.add(index, 1);
            long long numEleLeft = tree.sum(0, index-1);
            long long numEleRight = n - 1 - index - tree.sum(index+1, n-1);
            ans += numEleLeft * numEleRight;
        }
        return ans;
    }
};

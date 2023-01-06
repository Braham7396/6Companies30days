class Solution {
public:
    int D;
    long long merge(vector<int> &v, int l, int m, int r){
        int n1 = m-l+1, n2 = r-m;
        vector<int> left(n1), right(n2);
        for(int i=0;i<n1;i++) left[i] = v[l+i];
        for(int i=0;i<n2;i++) right[i] = v[m+1+i] + D;
        long long cnt = 0L;
        int i=0, j=0, k=l;
        while(i<n1 and j<n2){
            if(left[i] <= right[j]){
                i++;
                cnt += r - j - m;
            }
            else{
                j++;
            }
        }
        i = 0, j = 0;
        for(auto &x: right) x -= D;
        while(i<n1 and j<n2){
            if(left[i] < right[j]){
                v[k] = left[i];
                i++, k++;
            }
            else{
                v[k] = right[j];
                j++, k++;
            }
        }
        while(i < n1){
            v[k] = left[i];
            k++, i++;
        }
        while(j < n2){
            v[k] = right[j];
            k++, j++;
        }
        return cnt;
    }
    long long mergeSort(vector<int> &v, int l, int r){
        if(l < r){
            int m = (l + r) / 2;
            long long c1 = mergeSort(v, l, m);
            long long c2 = mergeSort(v, m+1, r);
            long long ci = merge(v, l, m, r);
            return c1 + ci + c2;
        }
        return 0L;
    } 
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        D = diff;
        int n = nums1.size();
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i] = nums1[i] - nums2[i];
        // v[i] <= v[j] + diff
        return mergeSort(v, 0, n-1);
    }
};

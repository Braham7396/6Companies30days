class Solution {
public:
        int minOperations(vector<int>& A, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for (int a: numsDivide)
            g = gcd(g, a);
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size() && A[i] <= g; ++i)
            if (g % A[i] == 0)
                return i;
        return -1;
    }
};

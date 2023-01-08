class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        double la = sqrt(pow(p1[0]-p2[0], 2) + pow(p1[1]-p2[1], 2));
        double lb = sqrt(pow(p1[0]-p4[0], 2) + pow(p1[1]-p4[1], 2));
        double lc = sqrt(pow(p3[0]-p2[0], 2) + pow(p3[1]-p2[1], 2));
        double ld = sqrt(pow(p3[0]-p4[0], 2) + pow(p3[1]-p4[1], 2));
        double d1 = sqrt(pow(p1[0]-p3[0], 2) + pow(p1[1]-p3[1], 2));
        double d2 = sqrt(pow(p4[0]-p2[0], 2) + pow(p4[1]-p2[1], 2));
        cout << "la " << la << endl;
        cout << "lb " << lb << endl;
        cout << "lc " << lc << endl;
        cout << "ld " << ld << endl;
        cout << "d1 " << d1 << endl;
        cout << "d2 " << d2 << endl;
        vector<double> v = {la,lb,lc,ld,d1,d2};
        sort(v.begin(), v.end());
        if(v[5] != v[4]) return false;
        for(int i=1;i<=3;i++)
            if(v[i] != v[i-1]) return false;
        if(v[4] > v[3]) return true;
        return false;
    }
};

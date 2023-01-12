class Solution {
public:
    class Compare{
        public:
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<long long, int>> cp(n+1, {INT_MAX, 0});
        for(int i=0;i<n;i++) cp[i] = {capital[i], profits[i]};
        sort(cp.begin(), cp.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(int i=0;i<n;i++){
            if(cp[i].first > w) break;
            pq.push({cp[i].first, cp[i].second});
            if(w < cp[i+1].first){
                while(w < cp[i+1].first and k and pq.size()){
                    auto x = pq.top();
                    w += x.second;
                    pq.pop();
                    k--;
                }
            }
            if(k == 0) break;
        }
        return w;
    }
};

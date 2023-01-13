class Solution {
public:
    pair<pair<string,string>,pair<int,int>> helper(string transaction){
        string name1,city1; int amt1=0,time1=0;
        bool a=0,b=0,c=0,d=0;
        for (int it=0; it<transaction.size(); it++){
            if (a==0){
                name1+=transaction[it];
                if (transaction[it+1]==','){
                    a=1; it++;
                }
            }
            else if (d==0){
                time1= time1*10;
                time1+= transaction[it]-'0';
                if (transaction[it+1]==','){
                    d=1; it++;
                }
            }
            else if (c==0){
                amt1= amt1*10;
                amt1+= transaction[it]-'0';
                if (transaction[it+1]==','){
                    c=1; it++;
                }
            }
            else if (b==0){
                city1+= transaction[it];
            }
            
        }
        return {{name1,city1},{amt1,time1}};
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        sort(transactions.begin(),transactions.end());
        //unordered_map<string,int> mp;
        int n= transactions.size();
        vector<string> ans;
        vector<bool> vis(n,0);
        for (int i=0; i<n; i++){
            //mp[transactions[i]]++;
            pair<pair<string,string>,pair<int,int>> t1= helper(transactions[i]);
            if (t1.second.first >=1000){
                vis[i]=1;
            }
            for (int j=i+1; j<n; j++){
                pair<pair<string,string>,pair<int,int>> t2= helper(transactions[j]);
                if ((t1.first.first==t2.first.first) && (abs(t2.second.second-t1.second.second)<=60) && (t1.first.second!=t2.first.second)){
                    vis[i]=1; vis[j]=1;
                }
            }
        }
        for (int i=0; i<n; i++){
            if (vis[i])ans.push_back(transactions[i]);
        }
        return ans;
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<pair<int, int>> match(10, {0, 0});
        int bulls = 0, cow = 0;
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i]) bulls++;
            else{
                match[secret[i]-'0'].first++;
                match[guess[i]-'0'].second++;
            }
        }
        for(int i=0;i<10;i++){
            cow += min(match[i].first, match[i].second);
        }
        string res = to_string(bulls) + 'A' + to_string(cow) + 'B';
        return res;
    }
};

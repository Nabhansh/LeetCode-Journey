class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string, string> mp;
        for(int i = 0; i<n; i++){
            mp[paths[i][0]] = paths[i][1];
        }
        string s = paths[0][0];
        while(mp.find(s) != mp.end()){
            s = mp[s];
        }
        return s;
    }
};
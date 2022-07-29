class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> data;
        for(int i = 0; i < logs.size(); ++i) {
            int user = logs.at(i).at(0);
            int time = logs.at(i).at(1);
            data[user].insert(time);
        }
        vector<int> res(k, 0);
        for(auto& d : data) {
            res.at(d.second.size()-1)++;
        }
        return res;
        
    }
};

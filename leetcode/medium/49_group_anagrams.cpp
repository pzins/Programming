class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> res;
        for(auto c : strs)
        {
            vector<int> alpha(26,0);
            for(int i = 0; i < c.size(); ++i)
            {
                alpha[c[i] - 'a']++;
            }
            string tmp = "";
            for(auto a : alpha) tmp += a;
            if(m.find(tmp) != m.end()) m[tmp].push_back(c);
            else m[tmp] = {c};
        }
        for(auto a : m)
        {
            res.push_back(a.second);
        }
        return res;
    }
};

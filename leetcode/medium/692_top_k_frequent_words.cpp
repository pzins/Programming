struct Comp {
    bool operator()(const pair<string, int> &lhs, const pair<string, int> &rhs) {
        if(lhs.second == rhs.second) return lhs.first < rhs.first; 
        return lhs.second > rhs.second;
    }
};



class Solution {
public:
    
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for(auto& a : words)
        {
            if(m.find(a) != m.end())
            {
                m[a]++;
            }
            else
            {
                m[a] = 1;
            }
        }
        
        std::vector<pair<string, int>> v(m.begin(), m.end());
        std::sort(v.begin(), v.end(), Comp());

        vector<string> res;
        int idx = 0;
        while(res.size() < k)
        {
            res.push_back(v.at(idx++).first);
        }
        return res;
    }
};

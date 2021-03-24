#include <map>
#include <set>

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto w : words)
        {
            if(w.size() != pattern.size()) continue;
            bool ok = true;
            map<char, char> m;
            set<char> s;
            for(int l = 0; l < w.size(); ++l)
            {
                if(m.find(w[l]) == m.end())
                {
                    m[w[l]] = pattern[l];
                    if(s.find(pattern[l]) != s.end())
                    {
                        ok = false;
                        break;
                    }
                    else {
                        s.insert(pattern[l]);
                    }
                }
                if(m[w[l]] != pattern[l])
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                res.push_back(w);
            }
        }
        return res;
    }
};

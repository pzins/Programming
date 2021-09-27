#include <algorithm>

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<char>> equals;
        vector<vector<char>> diff;
        vector<vector<char>> eq;
        for(auto& e : equations)
        {
            if(e[1] == '=')
            {
                int ok = false;
                for(int i = 0; i < equals.size(); ++i)
                {
                    if(find(equals[i].begin(), equals[i].end(), e[0]) != equals[i].end() && find(equals[i].begin(), equals[i].end(), e[3]) == equals[i].end())
                    {
                        equals[i].push_back(e[3]);
                        ok = true;
                    }
                    else if(find(equals[i].begin(), equals[i].end(), e[0]) == equals[i].end() && find(equals[i].begin(), equals[i].end(), e[3]) != equals[i].end())
                    {
                        equals[i].push_back(e[0]);
                        ok = true;
                    }
                }
                if(!ok)
                {
                    equals.push_back({e[0], e[3]});
                }
                eq.push_back({e[0], e[3]});
            }
            else
            {
                if(e[0] == e[3])
                    return false;
                diff.push_back({e[0], e[3]});
            }
        }
        
        
        for(auto& i : eq)
        {
            for(auto& e : equals)
            {
                if(find(e.begin(), e.end(), i[0]) != e.end() && find(e.begin(), e.end(), i[1]) == e.end())
                {
                    e.push_back(i[1]);
                }
                else if(find(e.begin(), e.end(), i[0]) == e.end() && find(e.begin(), e.end(), i[1]) != e.end())
                {
                    e.push_back(i[0]);
                }

            }
        }
        
        
        
        
        
        bool res = true;
        for(auto& d : diff)
        {
            // cout << "DIFF " << d[0] << "  " << d[1] << endl;
            for(auto& e : equals)
            {
                
                // for(auto& a : e) cout << a << " ";
                // cout << endl;
                if(find(e.begin(), e.end(), d[0]) != e.end() && find(e.begin(), e.end(), d[1]) != e.end())
                {
                    res = false;
                }
            }
        }
        return res;
    }
};

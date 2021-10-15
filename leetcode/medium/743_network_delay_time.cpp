class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
  
        vector<int> v(n+1, INT_MAX);
        v[k] = 0;
        
        std::set<int> P;      
        vector<vector<int>> cost(n+1, vector<int>(n+1, 0));
        map<int, vector<int>> succ;
        
        for(auto& t : times)
        {
            if(succ.find(t[0]) != succ.end())
            {
                succ[t[0]].push_back(t[1]);
            }
            else
            {
                succ[t[0]] = {t[1]};
            }
            cost[t[0]][t[1]] = t[2];
        }
        
        while(P.size() != n)
        {
            int i = 0;
            int mini = INT_MAX;
            for(int j = 1; j <= n; ++j)
            {
                if(v[j] <= mini and P.find(j) == P.end())
                {
                    i = j;
                    mini = v[j];
                }
            }        
           

            for(auto& s : succ[i]) // all succ
            {
                if(P.find(s) == P.end()) // not in P
                {
                    if(v[s] > long(v[i]) + cost[i][s])
                    {
                        v[s] = v[i] + cost[i][s];
                    }
                }
            }
            P.insert(i);
        }
        
        int res = 0;
        for(int i = 1; i < v.size(); ++i)
        {
            if(v[i] != INT_MAX)
                res = max(v[i], res);
            else return -1;

        }
        return res;

        
    }
};

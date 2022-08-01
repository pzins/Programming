class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> r;
        vector<int> p;
        for(int i = 0; i < m; ++i)
        {
            r.push_back(i+1);
            p.push_back(i);
        }
        vector<int> res;
        
        for(auto& q : queries) {
            // for(auto& a : p) cout << a << " ";cout << endl;
            int limit = p.at(q-1);
            
            r.erase(r.begin() + p.at(q-1));
            r.insert(r.begin(), q);
            res.push_back(p.at(q-1));
            
            
            for(int j = 0; j < p.size(); ++j)
            {
                if(j == q-1) p.at(j) = 0;
                else if(p.at(j) < limit) p.at(j)++;
            }
            
            
        }
        return res;
        
    }
};

class Solution {
public:
    
    void fct(int n, int k, int remain, vector<int> curr, set<vector<int>>& res)
    {
        if(curr.size() < k)
        {
            for(int i = remain; i <= n; ++i)
            {
                curr.push_back(i);
                fct(n, k, i+1, curr, res);
                curr.pop_back();
            }
            
        }
        if(curr.size() == k)
        {
            sort(curr.begin(), curr.end());
            res.insert(curr);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        set<vector<int>> res;
        vector<int> curr;
        
        fct(n, k, 1, curr, res);
        
        vector<vector<int>> resv;
        for(auto& i : res)
        {
            resv.push_back(i);
        }
        return resv;
        
    }
};

class Solution {
public:
    
    void fct(vector<vector<int>>& g, int r, int c, int curr, int& mini, vector<vector<int>>& v)
    {
        if(r < g.size() && c < g.at(0).size())
        {
            if(curr < v.at(r).at(c))
            {
                v.at(r).at(c) = curr;

                if(r == g.size()-1 && c == g.at(0).size()-1)
                {
                    if(curr < mini)
                        mini = curr;
                }
                if(r < g.size()-1)
                {
                    fct(g, r+1, c, curr + g.at(r+1).at(c), mini, v);
                }
                if(c < g.at(0).size()-1)
                {
                    fct(g, r, c+1, curr + g.at(r).at(c+1), mini, v);
                }
            }
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int res = 200*200*100+1;
        vector<vector<int>> v;
        for(int i = 0; i < grid.size(); ++i)
        {
            vector<int> tmp(grid.at(0).size(), 100000000000);
            v.push_back(tmp);
        }
        fct(grid, 0, 0, grid.at(0).at(0), res, v);
        return res;
    }
};

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int res = 0;
        for(int r = 0; r < grid.size(); ++r)
        {
            for(int c = 0; c < grid.at(r).size(); ++c)
            {
                
                int maxR = 0;
                for(int k = 0; k < grid.at(r).size(); ++k)
                {
                    if(grid.at(r).at(k) > maxR) maxR = grid.at(r).at(k);
                }
                int maxC = 0;
                for(int k = 0; k < grid.size(); ++k)
                {
                    if(grid.at(k).at(c) > maxC) maxC = grid.at(k).at(c);
                }
                
                int new_value = min(maxR, maxC);
                res += new_value - grid.at(r).at(c);
                grid.at(r).at(c) = new_value;
            }
        }
        return res;
    }
};

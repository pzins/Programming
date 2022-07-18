class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>> res;
        
        
        vector<vector<int>> curr(500);
        
        for(int i = 0; i < g.size(); ++i)
        {
            unsigned int size = g.at(i);
            curr.at(size).push_back(i);
            if(curr.at(size).size() == size)
            {
                res.push_back(curr.at(size));
                curr.at(size).clear();
            }
        }
        return res;
        
    }
};

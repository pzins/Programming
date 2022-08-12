class Solution {
public:
    
    void fct(string s, set<string>& res, string curr, vector<int> remain)
    {
        if(curr.size() > 0) res.insert(curr);
        for(int i = 0; i < s.size(); ++i)
        {
            if(remain.at(i) == 1)
            {
                remain.at(i) = 0;
                fct(s, res, curr + s.at(i), remain);
                remain.at(i) = 1;
            }
        }
    }
    
    
    int numTilePossibilities(string tiles) {
        set<string> res;
        vector<int> remain(tiles.size(), 1);
        string curr = "";
        
        for(int i = 0 ; i < tiles.size(); ++i)
        {
            fct(tiles, res, curr, remain);
        }
        return res.size();
        
        
    }
};

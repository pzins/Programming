class Solution {
public:
    
    int nb(int n, int r, int c, string s)
    {
        int res = 0;
        int cnt = 0;
        while(cnt < s.size() && r >= 0 && r < n && c >= 0 && c < n)
        {
            if(s.at(cnt) == 'U') r--;
            else if(s.at(cnt) == 'D') r++;
            else if(s.at(cnt) == 'L') c--;
            else if(s.at(cnt) == 'R') c++;
            if(r >= 0 && r < n && c >= 0 && c < n) res++;
            cnt++;
        }
        return res;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int r = startPos.at(0);
        int c = startPos.at(1);
        
        int h;
        int v;
        
        vector<int> res;
        for(int i = 0; i < s.size(); ++i)
        {
            int out = nb(n, r, c, s.substr(i, s.size()));
            res.push_back(out);
        }
        return res;
        
    }
};

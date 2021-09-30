class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
     
        for(int i = 0; i < m.size(); ++i)
        {
            int a = 0;
            int v = m[i][a];
            int ok = true;
            while(i+a < m.size() && a<m[0].size())
            {
                if(m[i+a][a] != v)
                {
                    ok = false;
                    break;
                }
                a++;
            }
            if (!ok)
            {
                return false;
            }
        }
        
        for(int i = 0; i < m[0].size(); ++i)
        {
            int a = 0;
            int v = m[a][i];
            int ok = true;
            while(i+a < m[0].size() && a < m.size())
            {
                if(m[a][i+a] != v)
                {
                    ok = false;
                    break;
                }
                a++;
            }
            if (!ok)
            {
                return false;
            }
        }
        return true;
    }
};

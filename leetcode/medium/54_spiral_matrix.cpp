class Solution {
public:
    
    int move(vector<vector<int>>& m, int i, int j, int prev)
    {
        vector<int> tmp(4, 0);
        if(j < m[0].size() - 1 && m[i][j+1] != 1000)
        {
            tmp[0] = 1;
        }
        if(i < m.size() - 1 && m[i+1][j] != 1000)
        {
            tmp[1] = 1;
        }
        if(j > 0 && m[i][j-1] != 1000)
        {
            tmp[2] = 1;
        }
        if(i > 0 && m[i-1][j] != 1000)
        {
            tmp[3] = 1;
        }
        
        int idx = prev-1;
        // for(auto a : tmp) cout << a << " ";
        // cout << endl;
        for(int k = 0; k < 4; ++k)
        {
            if(tmp[idx]) return idx+1;
            idx += 1;
            idx = idx % 4;
        }
        cout << "end" << endl;
        return 5;
        
    }
    
    vector<int> spiralOrder(vector<vector<int>>& m) {
        
        vector<int> res;
        int i = 0;
        int j = 0;
        int prev = 1;
        while(1)
        {
            res.push_back(m[i][j]);
            m[i][j] = 1000;
            int res  = move(m, i, j, prev);
            prev = res;
            if(res==1) j++;
            else if(res == 2) i++;
            else if(res == 3) j--;
            else if(res == 4) i--;
            else break;
        }
        return res;
        
        
    }
};

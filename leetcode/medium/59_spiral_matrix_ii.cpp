class Solution {
public:
    
    // 0: right; 1: down; 2: left; 3: up
    int move(vector<vector<int>>& data, int r, int c, int M)
    {
        int ok_R = (c+1 < data.at(r).size() && data.at(r).at(c+1) == 0);
        int ok_D = (r+1 < data.size() &&  data.at(r+1).at(c) == 0);
        int ok_L = (c-1 >= 0 &&  data.at(r).at(c-1) == 0);
        int ok_U = (r-1 >= 0 &&  data.at(r-1).at(c) == 0);
        
        if(M == 0 && ok_R) return 0;
        else if(M == 1 && ok_D) return 1;
        else if(M == 2 && ok_L) return 2;
        else if(M == 3 && ok_U) return 3;
        
        if(ok_R) return 0;
        else if(ok_D) return 1;
        else if(ok_L) return 2;
        else if(ok_U) return 3;
        
        return 4;
    }
    
    vector<vector<int>> generateMatrix(int n) {
    
        vector<vector<int>> res;
        for(int i = 0; i < n; ++i)
        {
            vector<int> tmp(n, 0);
            res.push_back(tmp);
        }

        int r = 0;
        int c = 0;
        int M = 0;
        for(int i = 1; i <= n*n; ++i)
        {            
            res.at(r).at(c) = i;
            int next = move(res, r, c, M);
            if(next == 0) c++;
            else if(next == 1) r++;
            else if(next == 2) c--;
            else if(next == 3) r--;
            else break;
            M = next;
        }
        return res;
        
    }
};

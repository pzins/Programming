class Solution {
public:
    
    vector<int> accu(vector<vector<int>>& v, int r, int c) {
        vector<int> res;
        while(r < v.size() && c < v.at(r).size())
        {
            res.push_back(v.at(r).at(c));
            r++;
            c++;
        }
        return res;
    }    
    void w(vector<vector<int>>& v, int r, int c, vector<int> data) {
        int i = 0;
        while(r < v.size() && c < v.at(r).size())
        {
            v.at(r).at(c) = data.at(i);
            i++;
            r++;
            c++;
        }
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> tmp;
        
        for(int row = mat.size()-1; row >= 0; --row)
        {
            vector<int> r = accu(mat, row, 0);
            tmp.push_back(r);
        }
        for(int col = 1; col < mat.at(0).size(); ++col)
        {
            vector<int> r = accu(mat, 0, col);
            tmp.push_back(r);
        }
        // for(auto i : tmp)
        // {
        //     for(auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        for(int i = 0; i < tmp.size(); ++i)
        {
            std::sort (tmp.at(i).begin(), tmp.at(i).end());
        }
        // for(auto i : tmp)
        // {
        //     for(auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        
        vector<vector<int>> res(mat);
        int cnt = 0;
        for(int row = mat.size()-1; row >= 0; --row)
            w(res, row, 0, tmp.at(cnt++));
        for(int col = 1; col < mat.at(0).size(); ++col)
            w(res, 0, col, tmp.at(cnt++));
        
        
        
        return res;
    }
};

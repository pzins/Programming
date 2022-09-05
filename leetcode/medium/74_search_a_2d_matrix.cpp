class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int idx = 0;
        int n = matrix.at(0).size();
        while(idx < matrix.size()-1 && matrix.at(idx).at(n-1) < target) idx++;
        for(int i = 0; i < n; ++i)
        {
            if(matrix.at(idx).at(i) == target) return true;
        }
        return false;
        
    }
};

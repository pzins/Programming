class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size();
        int col = mat.at(0).size();
        
        int square_size = min(row, col);
        
        vector<vector<int>> prefix(row + 1, vector<int>(col + 1, 0));
        
        for(int i = 0; i < prefix.size()-1; ++i)
        {
            for(int j = 0; j < prefix.at(0).size()-1; ++j)
            {
                prefix.at(i+1).at(j+1) = mat.at(i).at(j) + prefix.at(i+1).at(j) + prefix.at(i).at(j+1) - prefix.at(i).at(j);
            }
        }
        
        for(int k = square_size; k > 0; --k)
        {
            for(int i = k; i < row+1; ++i)
            {
                for(int j = k; j < col+1; ++j)
                {
                    int tot = prefix.at(i).at(j) - prefix.at(i-k).at(j) - prefix.at(i).at(j-k) + prefix.at(i-k).at(j-k);
                    if(tot <= threshold) return k;
                    
                }
            
                
            }
        }
        return 0;
        
        
    }
};

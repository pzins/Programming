class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size(), 0);
        
        for(int i = 0; i < res.size(); ++i)
        {
            int cnt = 0;
            for(int j = 0; j < boxes.size(); ++j)
            {
                if(boxes.at(j) == '1')
                {
                    cnt += abs(i - j);
                }
            }
            res.at(i) = cnt;
        }
        return res;
        
        
    }
};

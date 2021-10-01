class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        
        vector<int> cumu(arr.size(), 0);
        int tmp = arr[0];
        cumu[0] = tmp;
        for(int i = 1; i < arr.size(); ++i)
        {
            cumu[i] = tmp ^ arr[i];
            tmp = cumu[i];
        }
        
        
        for(auto& q : queries)
        {
            if(q[0] == q[1]){
                res.push_back(arr[q[0]]);
            }
            else if(q[0] == 0)
            {
                res.push_back(cumu[q[1]]);
            }
            else
            {
                res.push_back(cumu[q[1]] ^ cumu[q[0]-1]);
            }

        }
        return res;
        
    }
};

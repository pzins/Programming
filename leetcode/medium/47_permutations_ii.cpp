class Solution {
public:
    
    void fct(vector<int>& nums, vector<int>& curr, set<vector<int>>& res)
    {
        if(curr.size() == nums.size())
        {
            vector<int> vec;
            for(auto& a : curr) vec.push_back(a);
            res.insert(vec);
        }
        else
        {
            for(int j = 0; j < nums.size(); ++j)
            {
                if(nums[j] != 17)
                {
                    curr.push_back(nums[j]);
                    int tmp = nums[j];
                    nums[j] = 17;
                    fct(nums, curr, res);
                    curr.pop_back();
                    nums[j] = tmp;
                }
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        
        vector<int> curr;
        
        fct(nums, curr, s);
        
        vector<vector<int>> res;
        for(auto v : s)
        {
            res.push_back(v);
        }
        return res;
    }
};

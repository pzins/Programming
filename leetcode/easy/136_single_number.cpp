class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> v(6*10000, 0);
        for(auto& i : nums)
        {
            if(v[i+3*10000] == 0)
            {
                v[i+3*10000]++;
            }
            else
            {
                v[i+3*10000]--;
            }
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            {
                if(v[nums[i]+3*10000] != 0) return nums[i];
            }
        }
        return 0;
    }
};

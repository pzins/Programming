class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<unsigned int> zeros(32, 0);
        vector<unsigned int> ones(32, 0);
        for(int i = 0; i < nums.size(); ++i)
        {
            bitset<32> nb = nums[i];
            for(int j = 0; j < 32; ++j)
            {
                if(nb[j] == 0)
                {
                    zeros[j]++;
                }
                else
                {
                    ones[j]++;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < zeros.size(); ++i)
        {
            res += zeros[i] * ones[i];
        }
        return res;
       
    }
};

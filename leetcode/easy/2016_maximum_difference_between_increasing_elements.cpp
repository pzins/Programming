class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int curr = 0;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            int max = 0;
            for(int j = i+1; j < nums.size(); ++j)
            {
                if(nums.at(j) - nums.at(i) > max) max = nums.at(j) - nums.at(i);
            }
            if(max > curr) curr = max;
        }
        if(curr == 0) return -1;
        return curr;
    }
};


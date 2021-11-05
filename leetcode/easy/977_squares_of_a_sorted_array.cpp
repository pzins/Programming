class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int mini = INT_MAX;
        int minidx = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            nums[i] *= nums[i];
            if(nums[i] < mini)
            {
                mini = nums[i];
                minidx = i;
            }
        }
        int l = minidx-1;
        int r = minidx+1;
        res[0] = mini;
        for(int j = 1; j < nums.size(); ++j)
        {
            if(l < 0 || (l>=0 && r<nums.size() && nums[r] < nums[l]))
            {
                res[j] = nums[r];
                r++;
            }
            else
            {
                res[j] = nums[l];
                l--;
            }
        }
        return res;
    }
};

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = nums.at(0);
        int idx = 0;
        int sec = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums.at(i) > max)
            {
                sec = max;
                max = nums.at(i);
                idx = i;
            }
            else if(nums.at(i) > sec)
            {
                sec = nums.at(i);
            }
        }
        return max >= 2 * sec ? idx : -1;
    }
};

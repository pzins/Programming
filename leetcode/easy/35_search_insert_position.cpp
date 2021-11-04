class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int curr = 0;
        int l = 0;
        int r = nums.size()-1;
        if(target < nums.at(l)) return l;
        if(target > nums.at(r)) return r+1;
        while(l<=r)
        {
            curr = l + (r-l)/2;
            if(nums.at(curr) < target)
            {
                l = curr+1;
            }else
            {
                r = curr-1;
            }
        }
        return l;
    }
};

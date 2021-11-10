class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l<r)
        {
            if(r-l == 2)
            {
                if(nums[l] == nums[l+1]) return nums[r];
                return nums[l];
            }
            int mid = l + (r - l + 1) / 2;
            
            if((mid-l) % 2 == 0 && nums[mid] == nums[mid + 1])
            {
                l = mid;
            }
            else if((mid-l) % 2 == 1 && nums[mid] == nums[mid - 1])
            {
                l = mid + 1;
            }
            else if(((mid-l) % 2 == 0 && nums[mid] == nums[mid - 1]))
            {
                r = mid;
            }
            else if((mid-l) % 2 == 1 && nums[mid] == nums[mid + 1])
            {
                r = mid - 1;
            }
            else
            {
                return nums[mid];
            }
        }
        return nums[l];
    }
};

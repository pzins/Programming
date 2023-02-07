class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        while(l < r)
        {
            int mid = int((l + (r-l) / 2));
            cout <<  mid << " " << nums[mid] << " " <<  nums[mid+1] << endl;
            
            if(mid < nums.size()-1 && nums[mid]>nums[mid+1]) return nums[mid+1];
            if(mid > 0 && nums[mid-1]>nums[mid]) return nums[mid];

            if(nums[l] > nums[mid]) r = mid-1;
            else l = mid+1;
        }
        return nums[0];

    }
};

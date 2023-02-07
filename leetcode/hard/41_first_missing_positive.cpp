class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            while(nums[i] >= 1 && nums[i] <= nums.size() && nums[i]-1 != i && nums[i] != nums[nums[i]-1]) {
                //for(auto c : nums) cout << c << " "; cout << endl;
                swap(nums[i], nums[nums[i]-1]);
                //for(auto c : nums) cout << c << " "; cout << endl;
            };
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] < 1 || nums[i] > nums.size() || nums[i] - 1 != i)
                return i+1;
        }
        return nums.size()+1;
    }
};

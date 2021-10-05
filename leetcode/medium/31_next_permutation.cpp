class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool rot = false;
        for(int i = nums.size()-1; i >= 1; --i)
        {
            if(nums.at(i) > nums.at(i-1))
            {
                int swap_idx = i;
                int mini_supp = nums.at(i);
                for(int j = i; j < nums.size(); ++j)
                {
                    if(nums.at(j) < mini_supp && nums.at(j) > nums.at(i-1))
                    {
                        swap_idx = j;
                    }
                }
                int tmp = nums.at(swap_idx);
                nums.at(swap_idx) = nums.at(i-1);
                nums.at(i-1) = tmp;
                sort(nums.begin()+i, nums.end());
                rot = true;
                break;
            }
        }
        if(!rot)
        {
            reverse(nums.begin(), nums.end());
        }
        
    }
};

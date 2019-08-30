class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int cnt = 0;
        while(i < nums.size())
        {
            while(i < nums.size() && nums.at(i) == 0)
                i++;
            if(i >= nums.size()) break;
            swap(nums.at(i), nums.at(cnt));
            cnt++;
            i++;
        }
    }
};

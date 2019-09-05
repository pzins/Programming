class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return 0;
        int l = 0;
        int r = nums.size()-1;
        int s = 0;
        int ss = 0;
        for(auto a : nums) s += a;
        ss = s;
        for(int i = 0; i < nums.size(); ++i)
        {
            if((ss - nums.at(i)) % 2 == 0 && s - nums.at(i) == (ss - nums.at(i)) /2) return i;
            s -= nums.at(i);
        }
        return -1;
    }
};

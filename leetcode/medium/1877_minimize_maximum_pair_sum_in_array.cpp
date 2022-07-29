class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> rnums = nums;
        reverse(rnums.begin(), rnums.end());
        
        int max = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            int res  =nums.at(i) + rnums.at(i);
            if(res > max) max = res;
        }
        return max;
        
    }
};

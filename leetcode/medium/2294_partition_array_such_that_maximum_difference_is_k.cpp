class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int cnt = 0;

        int it = 0;
        while(it < nums.size())
        {
            int j = it;
            while(j < nums.size()-1 && nums.at(j+1) - nums.at(it) <= k)
            {
                j++;
            }
            cnt++;
            it = j + 1;
        }
        return cnt;
    }
};

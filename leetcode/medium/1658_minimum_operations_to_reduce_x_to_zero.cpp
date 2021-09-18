class Solution {
public:
    
    int findMaxLenSubarray(vector<int>& nums, int S, int x)
    {
        
        // create an empty map to store the ending index of the first subarray
        // having some sum
        map<int, int> map;

        // insert `(0, -1)` pair into the set to handle the case when a
        // subarray with sum `S` starts from index 0
        map[0] = -1;

        int target = 0;

        // `len` stores the maximum length of subarray with sum `S`
        int len = 0;

        // stores ending index of the maximum length subarray having sum `S`
        int ending_index = -1;

        // traverse the given array
        for (int i = 0; i < nums.size(); i++)
        {
            // sum of elements so far
            target += nums[i];

            // if the sum is seen for the first time, insert the sum with its
            // into the map
            if (map.find(target) == map.end()) {
                map[target] = i;
            }

            // update length and ending index of the maximum length subarray
            // having sum `S`
            if (map.find(target - S) != map.end() && len < i - map[target - S])
            {
                len = i - map[target - S];
                ending_index = i;
            }
        }
        
        cout << "[" << (ending_index - len + 1) << "," << ending_index << "]";
        if(ending_index == -1) return -1;
        
        return nums.size() - len;
        // return nums.size() - (ending_index - (ending_index - len + 1) + 1);
    }

    
    
    
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (auto& n : nums) total += n;
        if(total == x) return nums.size();
        return findMaxLenSubarray(nums, total-x, x);
        
    }
};

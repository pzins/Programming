class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size()-1;
        while(l < nums.size())
        {
            bool ok = true;
            for(int i = l+1; i < nums.size(); ++i)
            {
                if(nums[i] < nums[l])
                {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
            l++;
        }

        
        while(r >= 0)
        {
            bool ok = true;
            for(int i = r-1; i >= 0; --i)
            {
                if(nums[i] > nums[r])
                {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
            r--;
        }


        if(l >= r) return 0;
        return r-l+1;
    }
};

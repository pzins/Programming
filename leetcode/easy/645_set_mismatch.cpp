class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> d(10001, 0);
        int maxi = 0;
        for(int j = 0; j < nums.size(); ++j)
        {
            if(nums.at(j) > maxi) maxi = nums.at(j);
            
            d.at(nums.at(j)) += 1;
        }
        
        int a = -1;
        int b = -1;
        for(int j = 1; j <= maxi; ++j)
        {
            if(d.at(j) == 2) a = j;
            if(d.at(j) == 0) b = j;
        }
        if(b == -1) b = maxi+1;
        return {a,b};
    }
};

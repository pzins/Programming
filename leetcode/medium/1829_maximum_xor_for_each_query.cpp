class Solution {
public:

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> xors(nums.size());
        vector<int> res;
        int curr = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            xors.at(i) = curr ^ nums.at(i);
            curr = xors.at(i);
        }
        long long unsigned int maxi = pow(2, maximumBit) - 1;
        for(int i = 0; i < xors.size(); ++i)
        {
            res.push_back(xors.at(i) ^ maxi);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

    

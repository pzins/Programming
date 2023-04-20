class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> vec(501, 0);
        for(auto i : nums)
        {
            vec.at(i)++;
        }
        
        for(auto i : vec)
        {
            if(i % 2 != 0 && i != 0) return false;
        }
        return true;
    }
};

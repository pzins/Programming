class Solution {
public:
    
    
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> low;
        vector<int> eq;
        vector<int> up;
        for(auto& i : nums)
        {
            if(i < pivot) low.push_back(i);
            else if(i > pivot) up.push_back(i);
            else eq.push_back(i);
        }
        vector<int> res;
        for(auto a : low) res.push_back(a);
        for(auto a : eq) res.push_back(a);
        for(auto a : up) res.push_back(a);
        return res;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        std::map<int, int> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            int nb = nums.at(i);
            if(m.find(nb) != m.end())
            {
                if(i - m.at(nb) <= k)
                    return true;
                else
                    m[nb] = i;
            }
            else
            {
                m[nb] = i;
            }
        }
        return false;
    }
};

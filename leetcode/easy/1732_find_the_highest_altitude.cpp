class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int res = 0;
        for(auto i : gain)
        {
            curr += i;
            res = max(res, curr);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end(), greater<int>());
        vector<int> res;
        vector<int> tmpK = {tmp.begin(), tmp.begin()+k};
        if(nums.size() == 1) return nums;
        for(auto& i : nums)
        {
            //cout << *tmp.begin() << " " << *(tmp.begin()+1) << " " << *(tmp.begin()+2) << endl;
            //cout << i << endl;
            auto it = std::find(tmpK.begin(), tmpK.end(), i);
            if(it != tmpK.end())
            {
                res.push_back(i);
                tmpK.erase(it);
            }
            if(res.size() == k) break;
        }
        return res;
    }
};

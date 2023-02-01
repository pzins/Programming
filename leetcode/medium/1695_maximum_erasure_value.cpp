class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int maxi = 0;
        int left = 0;
        int right = 0;
        map<int, int> m;
        vector<int> cumu = {nums.at(0)};
        for(int i = 1; i < nums.size(); ++i) {
            cumu.push_back(cumu.at(i-1) + nums.at(i));
        }

        while(right < nums.size())
        {
            auto it = m.find(nums.at(right));
            if(it == m.end())
            {
                m[nums.at(right)] = right;
            }
            else if(it->second >= left)
            {
                int avant = 0;
                if(left > 0) avant = cumu[left-1];
                int tmp = cumu[right-1] - avant;
                left =  m[nums.at(right)] + 1;
                m[nums.at(right)] = right;

                if(maxi < tmp) maxi = tmp;

            }
            else
            {
                m[nums.at(right)] = right;
            }
            right++;
        }
        int avant = 0;
        if(left > 0) avant = cumu[left-1]; 
        int tmp = cumu[right-1] - avant;
        if(maxi < tmp) maxi = tmp;

        return maxi;
    }
};

class Solution {
public:
       
    int deleteAndEarn(vector<int>& nums) {        
        map<int, int> m;
        for(auto& a : nums)
        {
            m[a]++;
        }
        
        vector<vector<int>> v;
        for(auto& a : m)
        {
            v.push_back({a.first, a.second});
        }
        vector<int> dp(v.size(), 0);
        dp[0] = v[0][0] * v[0][1];
        
        for(int i = 1; i < v.size(); ++i)
        {
            int gain = v[i][0] * v[i][1];
            if(abs(v[i-1][0]-v[i][0]) > 1)
            {
                dp[i] = dp[i-1] + gain;
            }
            else
            {
                int a = 0;
                if(i < 2)
                {
                    a = gain;
                }
                else
                {
                    a = dp[i-2] + gain;
                }
                int b = dp[i-1];
                dp[i] = max(a, b);
            }
        }
        return dp[dp.size()-1];
    }
};

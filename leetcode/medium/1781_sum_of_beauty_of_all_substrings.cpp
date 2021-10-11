class Solution {
public:
    
    int beauty(vector<int>& v)
    {
        int maxi = 0;
        int mini = 0;
        for(auto& i : v)
        {
            if(i > maxi) maxi = i;
            if(i > 0 && (mini == 0 || i < mini)) mini = i;
        }
        return maxi - mini;
    }
    
    int beautySum(string s) {
        vector<vector<int>> f(s.size()-1, vector<int>(26,0));
        int res = 0;
        
        for(int i = 0; i < s.size()-1; ++i)
        {
            f[i][s[i] - 'a']++;
            for(int j = i+1; j < s.size(); ++j)
            {
                f[i][s[j] - 'a']++;
                int tmp = beauty(f[i]);
                res += tmp;
            }
        }
        return res;
    }
    
};

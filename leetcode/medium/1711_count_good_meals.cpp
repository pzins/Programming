class Solution {
public:
    
    int countPairs(vector<int>& d) {
        long long cnt = 0;
        unordered_map<int, int> m;
        for(auto& it : d)
        {
            for(int j = 0; j <= 21; ++j)
            {
                int p = 1<<j;
                if(m.find(p - it) != m.end())
                {
                    cnt = cnt + m[p - it];
                }
            }
            m[it]++; // add only at the end, so it's not found directly and the sum is not counted twice
        }
        return (int)(cnt%1000000007);
    }
};


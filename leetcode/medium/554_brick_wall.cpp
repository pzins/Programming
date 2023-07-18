class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> m;
        for(auto& a : wall)
        {
            int count = 0;
            for(int i = 0; i < a.size()-1; ++i)
            {
                count += a[i];
                
                if(m.find(count) == m.end())
                {
                    m[count] = 1;
                }
                else
                {
                    m[count]++;
                }
            }
        }
        int maxi = 0;
        for(auto& n : m)
        {
            //cout << n.first << " " << n.second << endl;
            if(n.second > maxi) maxi = n.second;
        }
        return wall.size() - maxi;
    }
};

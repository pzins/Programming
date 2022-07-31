class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
  
        vector<int> v;
        for(auto& a : points)
        {
            v.push_back(a.at(0));
        }
        sort(v.begin(), v.end());
        
        int max = 0;
        for(int i = 0; i < v.size()-1; ++i)
        {
            int diff = v.at(i+1) - v.at(i);
            if(diff > max) max = diff;
        }
        return max;
    }
};

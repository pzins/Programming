class Solution {
public:
    
    int minAreaRect(vector<vector<int>>& pts) {    
        unordered_map<int,unordered_set<int>> m;
        for(auto a : pts)
        {
            m[a[0]].insert(a[1]);
        }
        
        int mini = -1;
        for(int i = 0; i < pts.size(); ++i)
        {
            for(int j = i+1; j < pts.size(); ++j)
            {
                if(i != j)
                {
                    if( m.find(pts[i][0]) != m.end() && m[pts[i][0]].count(pts[j][1]) && m.find(pts[j][0]) != m.end() && m[pts[j][0]].count(pts[i][1]))
                    {
                        int area = abs(pts[i][1] - pts[j][1]) * abs(pts[i][0] - pts[j][0]);
                        if(area > 0 && (mini == -1 || area < mini))
                            mini = area;
                    }
                }
            }
        }
        if(mini == -1) return 0;
        return mini;
        
        
    }
};

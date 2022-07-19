class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto q: queries) {
            int r = 0;
            for(auto p : points) {
                double res = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                if(res <= q[2]*q[2]) r++;
            }
            res.push_back(r);
        }
        return res;
    }
};

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if((points.at(0).at(0) == points.at(1).at(0) && points.at(0).at(1) == points.at(1).at(1)) ||
            (points.at(0).at(0) == points.at(2).at(0) && points.at(0).at(1) == points.at(2).at(1)) ||
            (points.at(1).at(0) == points.at(2).at(0) && points.at(1).at(1) == points.at(2).at(1)))
            return false;
           
        if(points.at(1).at(0) - points.at(0).at(0) == 0)
        {
            return !(points.at(2).at(0) == points.at(0).at(0) && points.at(0).at(1) != points.at(1).at(1) &&
                    points.at(2).at(1) != points.at(0).at(1));
        }
        if(points.at(2).at(0) - points.at(0).at(0) == 0)
        {
            return !(points.at(1).at(0) == points.at(0).at(0) && points.at(0).at(1) != points.at(1).at(1) &&
                    points.at(2).at(1) != points.at(0).at(1));
        }
        
        return float((points.at(1).at(1) - points.at(0).at(1))) / (points.at(1).at(0) - points.at(0).at(0))
            != float((points.at(2).at(1) - points.at(0).at(1))) / (points.at(2).at(0) - points.at(0).at(0));
    }
};

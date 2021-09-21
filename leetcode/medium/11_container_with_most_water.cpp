class Solution {
public:
    
    int area(vector<int>& height, int i, int j)
    {
        return min(height.at(i), height.at(j)) * (j-i);
    }
    
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        
        int best = area(height, l, r);

        while(l != r)
        {
            int a = area(height, l, r);
            if(a > best) best = a;
            if(height.at(l) <= height.at(r)) l++;
            else r--;
        }
        return best;
        
        
//         for(int i = 0; i < height.size()-1; ++i)
//         {
//             for(int j = i+1; j < height.size(); ++j)
//             {
//                 area = min(height.at(i), height.at(j)) * (j-i);
//                 if(area > best)
//                     best = area;
                
//             }
//         }
//         return best;
    }
};

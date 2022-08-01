class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int curr = capacity;
        int res = 0;
        for(int i = 0; i < plants.size(); ++i)
        {
            if(curr < plants.at(i))
            {
                res += i*2;
                curr = capacity;   
            }
            
            curr -= plants.at(i);
            res += 1;
        }
        return res;
    }
};

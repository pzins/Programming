class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        unsigned long long int M = mass;
        sort(asteroids.begin(), asteroids.end());
        for(auto& a : asteroids)
        {
            if(M < a) return false;
            else
            {
                M += a;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res(bound+1);
        int l = 0;
        int r = 0;
        for(int i = 0; i < bound; ++i)
        {
            l = pow(x, i);
            if(l >= bound)
                break;
            
            for(int j = 0; j < bound; ++j)
            {
                r = pow(y, j);
                if(l + r > bound)
                    break;
                else
                    res.at(l + r) = 1;
            }
        }
        vector<int> realres;
        for(int i = 0; i < res.size(); ++i)
        {
            if(res.at(i) == 1)
                realres.push_back(i);
        }
        return realres;
    }
};

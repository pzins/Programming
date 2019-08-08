#include <algorithm>

class Solution {
public:
    void p(std::vector<int>& v)
    {
        std::cout << "==== v === : ";
        for(auto& i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size() % W != 0) return false;
        sort(hand.begin(), hand.end());
        std::vector<int> v(hand.size());
        
    
        for(int batch = 1; batch < hand.size()/W+1; ++batch)
        {
            int i = 0;
            int tmp = 1;
            int last = 0;
            
            for(int j = 0; j < hand.size(); ++j)
            {
                if(v.at(j) == 0)
                {
                    last = j;
                    v.at(j) = batch;
                    i = j+1;
                    break;
                }
            }
            while(tmp < W)
            {
                if(i >= hand.size())
                {
                    return false;
                }
                if(v.at(i) != 0)
                {
                    i++;
                    continue;
                }
                if(i == 0)
                {
                    v.at(i) = batch;
                    tmp++;
                }
                else if(hand.at(last) + 1 == hand.at(i))
                {
                    v.at(i) = batch;
                    last = i;
                    tmp++;
                }
                else if(hand.at(last) == hand.at(i))
                {
                    
                }
                else if(hand.at(last) + 1 != hand.at(i) && tmp < W)
                {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};
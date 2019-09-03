class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::sort(stones.begin(), stones.end());
        
        while(stones.size() > 1)
        {
            int end = stones.size() - 1;
            if(stones.at(end) != stones.at(end - 1))
            {
                stones.at(end - 1) = stones.at(end) - stones.at(end - 1);
                stones.pop_back();
                int idx = stones.size() - 1;
                
                while(idx > 0 && stones.at(idx-1) > stones.at(idx))
                {
                    swap(stones.at(idx-1), stones.at(idx));
                    idx--;
                }
                
            }
            else
            {
                stones.pop_back();
                stones.pop_back();
            }
        }
        
        return stones.size() > 0 ? stones.at(0) : 0;
    }
};

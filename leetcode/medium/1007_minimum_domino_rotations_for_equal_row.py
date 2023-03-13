#include <algorithm>    // std::min
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> to_test = {tops[0], bottoms[0]};
        bool glob_ok = false;
        unsigned long mini = 10000000000;
        for(auto t : to_test)
        {
            unsigned long swap = 0;
            unsigned long swap2 = 0;
            
            bool ok = true;
            bool ok2 = true;
            for(int i = 0; i < tops.size(); ++i)
            {
                if(tops[i] == t) {
                    swap += 0;
                }
                else if (bottoms[i] == t){
                    swap++;
                }
                else
                {
                    ok = false;
                }
                if(bottoms[i] == t) {
                    swap2 += 0;
                }
                else if (tops[i] == t){
                    swap2++;
                }
                else
                {
                    ok2 = false;
                }
                if(!ok || !ok2) break;
            }
            if(ok || ok2)
            {
                glob_ok = true;
                mini = min(mini, min(swap, swap2));
            }
        }
        if(!glob_ok) return -1;
        return mini;
    }
};

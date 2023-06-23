#include <string>

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        map<int, vector<string>> m;
        
        for(auto& a : nums)
        {
            m[a.size()].push_back(a);
        }

        for(auto i = m.rbegin(); i != m.rend(); ++i)
        {
            //cout << i->first << " " << i->second.size() << endl;
            if(k <= i->second.size())
            {
                auto& vec = i->second;
                sort(vec.begin(), vec.end());
                for(int o = vec.size()-1; o >= 0; o--)
                {
                    //cout << k << endl;
                    if(k == 1) return vec[o];
                    k--;
                }
            }
            k -= i->second.size();
        }
        return "";
    }
};

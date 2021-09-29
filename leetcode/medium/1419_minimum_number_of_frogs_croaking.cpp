#include <algorithm>    // std::max

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        
        stack<int> s;
        int maxi = 0;
        map<char, int> m;
        m['c'] = 0;
        m['r'] = 0;
        m['o'] = 0;
        m['a'] = 0;
        m['k'] = 0;
        for(auto& l : croakOfFrogs)
        {
            if(l =='r')
            {
                if(m['c'] <= m['r']) return -1;
            }
            else if(l =='o')
            {
                if(m['r'] <= m['o']) return -1;
            }
            else if(l =='a')
            {
                if(m['o'] <= m['a']) return -1;
            }
            else if(l =='k')
            {
                if(m['a'] <= m['k']) return -1;
            }
            
            
            
            m[l]++;
            
            if(l == 'c')
                s.push(1);
            else if(l == 'k')
                s.pop();
            maxi = max(maxi, int(s.size()));
        }

        int v = m['c'];
        for(auto& l : m)
        {
            if(l.second != v) return -1;
        }
        return maxi;
        
    }
};

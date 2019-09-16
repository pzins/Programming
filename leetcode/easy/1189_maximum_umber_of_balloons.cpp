class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> m;
        m['b'] = 0;
        m['a'] = 0;
        m['l'] = 0;
        m['o'] = 0;
        m['n'] = 0;
        for(int i = 0; i < text.size(); ++i)
        {
            if(m.find(text.at(i)) != m.end())
            {
                m[text.at(i)]++;
            }
        }
        int min = -1;
        for(auto& e : m)
        {
            if(e.first == 'l' || e.first == 'o')
            {
                if(min == -1 || e.second/2 < min)
                {
                    min = e.second/2;
                }
                
            }
            else
            {
                if(min == -1 || e.second < min)
                {
                    min = e.second;
                }
            }
        }
        return min;
    }
};

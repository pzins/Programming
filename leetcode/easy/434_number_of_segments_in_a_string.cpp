class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0)
            return 0;
        int x = 0;
        int res = 0;
        bool count = false;
        while(x < s.size())
        {
            if(s.at(x) != ' ')
                count = true;
            if(count)
            {
                if(s.at(x) == ' ')
                {
                    res++;
                    count = false;
                }
            }
            x++;
        }
        if(s.at(s.size()-1) != ' ')
            res++;
        return res;
    }
};

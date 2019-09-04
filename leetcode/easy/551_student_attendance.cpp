class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s.at(i) == 'A')
            {
                a++;
                if(a> 1) return false;
            }
            if(s.at(i) == 'L' && i+1 < s.size() && s.at(i+1) == 'L'
                && i+2 < s.size() && s.at(i+2) == 'L')
            {
                return false;
            }
        }
        return true;
    }
};

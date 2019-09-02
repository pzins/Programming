class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        if(s.size() <= 2)
            return true;
        bool ok = true;
                
        while(i < s.size() / 2)
        {
            if(s.at(i) == s.at(j))
            {
                i++;
                j--;
            }
            else
            {
                if(ok)
                {
                    
                    if((s.at(i+1) == s.at(j)) && ((i+2 >= s.size()/2) || s.at(i+2) == s.at(j-1)))
                    {
                        i++;
                    }
                    else if((s.at(i) == s.at(j-1)) && ((j-2 <= s.size()/2) || s.at(i+1) == s.at(j-2)))
                    {
                        j--;
                    }
                    ok = 0;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

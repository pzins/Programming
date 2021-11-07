class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while(i < s.size())
        {
            int begin = i;
            while(i < s.size() && s[i] != ' ') i++;
            
            for(int j = begin; j < begin + (i-begin)/2; ++j)
            {
                swap(s[j], s[i-1-(j-begin)]);
            }
            while(i < s.size() && s[i] == ' ') i++;
        }
        return s;
        
    }
};

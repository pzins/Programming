class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = 0;
        vector<string> v;
        while(i < s.size())
        {
            while(i < s.size() && s.at(i) == ' ')
            {
                i++;
            }
            if(i == s.size()) break;
            string tmp = "";
            while(i < s.size() && s.at(i) != ' ')
            {
                tmp += s.at(i);
                i++;
            }
            v.push_back(tmp);
        }
        for(int i = v.size() - 1; i >= 0; --i)
            res += v.at(i) + " ";
        res.erase(res.end()-1);
        return res;
        
    }
};

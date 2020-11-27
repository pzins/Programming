class Solution {
public:
    int numJewelsInStones(string J, string S) {
        std::set<char> s;
        for(auto& i : J)
        {
            s.insert(i);
        }
        unsigned int r = 0;
        for(auto& i : S)
        {
            if(s.find(i) != s.end())
            {
                r++;
            }
        }
        return r;
    }
};

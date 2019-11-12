class Solution {
public:
    bool buddyStrings(string A, string B) {
        char a;
        char b;
        int diff = -1;
        if(A.size() != B.size()) return false;
        unordered_set<char> s;
        for(int i = 0; i < A.size(); ++i)
        {
            s.insert(A.at(i));
            if(A.at(i) != B.at(i))
            {
                if(diff == -1)
                {
                    a = A.at(i);
                    b = B.at(i);
                    diff = i;
                }
                else if(diff == -2)
                {
                    return false;
                }
                else
                {
                    if(!(B.at(i) == a && A.at(i) == b)) return false;
                    diff = -2;
                }
            }
        }
        if(diff == -1)
        {
            if(s.size() < A.size()) return true;
            return false;
        }
        return true;
    }
};

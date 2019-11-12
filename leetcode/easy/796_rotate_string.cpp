class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A.size() == 0) return true;
        char start = A.at(0);
        for(int i = 0; i < B.size(); ++i)
        {
            if(B.at(i) == start)
            {
                string tmp = "";
                tmp += B.substr(i, B.size() - i) + B.substr(0, i);
                if(tmp == A) return true;
            }
        }
        return false;
    }
};

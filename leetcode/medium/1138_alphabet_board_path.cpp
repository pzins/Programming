class Solution {
public:
    string alphabetBoardPath(string target) {
        int r_ = 0;
        int c_ = 0;
        string res = "";
        for(auto& l : target)
        {
            int t = int(l) - 97;
            int r = t / 5;
            int c = t % 5;
            
            // Two special cases for the 'z'
            if(t == 25) {
                while(c_ != 0) {
                    res += "L";
                    c_--;
                }
            }
            if(r_ == 5 && r != r_)
            {
                res += "U";
                r_--;
            }
            
            while(r != r_)
            {
                if(r < r_) {
                    res += "U";
                    r_--;
                }
                else if(r > r_) {
                    res += "D";
                    r_++;
                }
            }

            while(c != c_)
            {
                if(c > c_) {
                    res += "R";
                    c_++;
                }
                else if(c < c_) {
                    res += "L";
                    c_--;
                }
            }
            
            res += "!";
        }
        return res;
    }
};

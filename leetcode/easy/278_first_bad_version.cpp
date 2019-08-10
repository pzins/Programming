// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int curr = 1;
        int l = 1;
        int r = n;
        if(isBadVersion(1)) return 1;
        if(n == 2 && isBadVersion(1)) return 1;
        else if(n == 2) return 2;
        while(l <= r)
        {
            curr = l + (r-l)/2;
            bool res = isBadVersion(curr);
            if(curr == 1) return 1;
            bool prev = isBadVersion(curr - 1);
            if(res && !prev)
            {
                return curr;
            }
            else if(res)
            {
                r = curr - 1;
            }
            else
            {
                l = curr + 1;
            }
        }
        return curr;
        
        
    }
};

class Solution {
public:
    int minOperations(int n) {
        int res = 0; 
        int i = n-1;
        while(i > 0)
        {
            res += i;
            i -= 2;
        }
        return res;
    }
};

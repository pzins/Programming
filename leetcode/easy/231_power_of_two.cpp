class Solution {
public:
    bool isPowerOfTwo(int n) {
        double res = 1;
        while(res < n) res *= 2;
        return n==res;
        
    }
};

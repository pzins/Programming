class Solution {
public:
    bool isPowerOfFour(int num) {
        double ol = 1;
        while(ol < num)
        {
            ol *= 4;
        }
        return ol==num;
    }
};

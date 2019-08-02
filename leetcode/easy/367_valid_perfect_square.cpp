class Solution {
public:
    bool isPerfectSquare(int num) {
        double curr = 1;
        while(curr*curr < num)
            curr++;
        return curr*curr == num;
    }
};
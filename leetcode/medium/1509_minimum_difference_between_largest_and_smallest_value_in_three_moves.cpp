class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());

        int case1 = nums.at(nums.size()-4) - nums.at(0);
        int case2 = nums.at(nums.size()-3) - nums.at(1);
        int case3 = nums.at(nums.size()-2) - nums.at(2);
        int case4 = nums.at(nums.size()-1) - nums.at(3);


        if(case1 <= case2 && case1 <= case3 && case1 <= case4) return case1;
        else if(case2 <= case1 && case2 <= case3 && case2 <= case4) return case2;
        else if(case3 <= case1 && case3 <= case2 && case3 <= case4) return case3;
        else return case4;
    }
};

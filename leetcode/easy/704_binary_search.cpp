class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = l + int((r-l+1) / 2);
        if(nums.at(mid) == target) return mid;
        while(l<r)
        {
            if(nums.at(l) == target) return l;
            if(nums.at(r) == target) return r;
            mid = l + int((r-l+1) / 2);
            cout << l << " " << r << " " << mid << endl;
            if(nums.at(mid) == target)
            {
                return mid;
            }
            else if(nums.at(mid) < target){
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        if(nums.at(mid) == target) return mid;
        else return -1;
    }
};

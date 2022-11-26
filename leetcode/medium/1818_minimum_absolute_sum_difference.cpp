class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diff;
        long int res = 0;
        vector<int> elements(100001, 0);
        for(int i = 0; i < nums1.size(); ++i)
        {
            int tmp = abs(nums1.at(i) - nums2.at(i));
            diff.push_back(tmp);
            res += tmp;
            elements.at(nums1.at(i)) = 1;
        }
        int max_gain = 0;
        for(int i = 0; i < diff.size(); ++i)
        {
            int right = 0;
            while(nums2.at(i)+right < elements.size() and elements.at(nums2.at(i)+right) == 0)
            {
                right++;
            }
            int left = 0;
            while(nums2.at(i)+left >= 0 and elements.at(nums2.at(i)+left) == 0)
            {
                left--;
            }
            int offset = 0;
            if(-left < right && nums2.at(i)+left >= 0)
                offset = left;
            else if(nums2.at(i)+right < elements.size())
                offset = right;

            int replacement = nums2.at(i)+offset;
            int new_diff = abs(replacement - nums2.at(i));
            int gain = diff.at(i) - new_diff;
            if(gain > max_gain)
            {
                max_gain = gain;
            }

        }
        cout << max_gain << endl;
        return (res - max_gain) % (1000000000+7);
    }
};

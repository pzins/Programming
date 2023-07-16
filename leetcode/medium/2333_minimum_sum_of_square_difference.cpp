class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> v(1e5+1, 0);
        for(int i = 0; i < nums1.size(); ++i)
        {
            v[abs(nums1[i] - nums2[i])]++;
        }

        int k = k1 + k2;
        for(int i = 1e5; i >= 0; --i)
        {
            if(v[i] <= k)
            {
                if(i <= 1)
                {
                    return 0;
                }
                k -= v[i];
                v[i-1] += v[i];
                v[i] = 0;
            }
            else
            {

                if(i==0) return 0;
                v[i] -= k;
                v[i-1] += k;
                break;
            }

        }

        long long res = 0;
        for(int i = 1; i < v.size(); ++i){
            res += v[i] * ((long long) i * i);
        }
        return res;
    }
};

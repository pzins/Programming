class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1000000001);
        int id_max = -1;
        int maxi = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(id_max == -1 || nums.at(i) > maxi)
            {
                maxi = nums.at(i);
                id_max = i;
            }
        }
        res[id_max] = -1;
        int i = id_max;
        for(int o = 0; o < n; ++o)
        {
            int prev = i-1;
            if(prev == -1) prev = n-1;

            if(nums.at(prev) < nums.at(i)) res.at(prev) = nums.at(i);
            else
            {
                for(int k = 0; k < n; ++k)
                {
                    if(res.at((i+k)%n) == 1000000001) break;
                    if(res.at((i+k) % n) > nums.at(prev)) {
                        res.at(prev) = res.at((i+k)%n);
                        break;
                    }
                }
            }
            i--;
            if(i == -1) i = n-1;
        }

        for(int i = 0; i < res.size(); ++i)
        {
            if(res.at(i) == 1000000001) res.at(i) = -1;
        }
        return res;
    }
};



// Naive solution TLE
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res(n, 1000000001);
//         int offset = 1;
//         while(offset <= (n-1))
//         {   int change = false;
//             for(int i = 0; i < res.size(); ++i)
//             {
//                 if(res.at(i) == 1000000001){
//                     if(nums.at(i) < nums.at((i+offset) % n))
//                         res.at(i) = nums.at((i+offset) % n);
//                     change = true;
//                 }
//             }
//             if(change == false) break;
//             offset++;
//         }
//         for(int i = 0; i < res.size(); ++i)
//         {
//             if(res.at(i) == 1000000001) res.at(i) = -1;
//         }
//         return res;
//     }
// };

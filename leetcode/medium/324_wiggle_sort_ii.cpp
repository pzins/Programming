class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() > 1)
        {
            sort(nums.begin(), nums.end());
            int l = nums.size()/2-1;
            if(nums.size() % 2 == 1)
            {
                l = nums.size()/2;
            }
            
            int r = nums.size()-1;
            
            vector<int> res;
            
            
            while(res.size() != nums.size())
            {
                res.push_back(nums[l--]);
                if(res.size() != nums.size())
                    res.push_back(nums[r--]);
            }

//             int idx;
//             while(res.size() != nums.size())
//             {
//                 // cout << "A:"; for(auto a : res) cout << a << " "; cout << endl;
//                 idx = middle+1;
//                 while(idx < nums.size() && (nums[idx] == res.at(res.size()-1) || remains[idx] == 0)) idx++;
//                 if(idx < nums.size())
//                 {
//                     res.push_back(nums[idx]);
//                     remains[idx] = 0;
//                 }
//                 if(res.size() == nums.size()) break;
//                 // cout << "B:"; for(auto a : res) cout << a << " "; cout << endl;

//                 idx = middle-1;
//                 while(idx > 0 && (nums[idx] == res.at(res.size()-1) || remains[idx] == 0)) idx--;
//                 if(idx >= 0)
//                 {
//                     res.push_back(nums[idx]);
//                     remains[idx] = 0;
//                 }
//                 // cout << "C:"; for(auto a : res) cout << a << " "; cout << endl;
//                 // cout << "---" << res.size() << endl;
//             }
            nums = res;
        }
    }
};

class Solution {
public:
    
    void print(vector<int>& v) {
        cout << "Array ";
        for(auto& i : v) cout << i << " ";
        cout << endl;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> res(nums.size());
        
        int p = 0;
        int n = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums.at(i) < 0) {
                res[n] = nums.at(i);
                n += 2;
            } else {
                res[p] = nums.at(i);
                p += 2;
            }
        }
        return res;
        
        
        
//         bool is_pos = true;
        
//         int curr = 0;
//         while(curr < nums.size())
//         {
//             // print(nums);
//             if(is_pos)
//             {
//                 // cout << "Pos " << nums.at(curr) << endl;
//                 int pos = curr;
//                 while(pos < nums.size() && nums.at(pos) < 0) pos++;
//                 if(pos >= nums.size()) break;
//                 while(curr != pos) {
//                     int tmp = nums.at(pos);
//                     nums.at(pos) = nums.at(pos-1);
//                     nums.at(pos-1) = tmp;
//                     pos--;
//                 }
//             }
//             else {
//                 // cout << "Neg " << nums.at(curr) << endl;
//                 int neg = curr;
//                 while(neg < nums.size() && nums.at(neg) > 0) neg++;
//                 if(neg >= nums.size()) break;
//                 while(curr != neg) {
//                     int tmp = nums.at(neg);
//                     nums.at(neg) = nums.at(neg-1);
//                     nums.at(neg-1) = tmp;
//                     neg--;
//                 }
                
//             }
//             curr++;
//             is_pos = !is_pos;
//         }

        return nums;
    }
};

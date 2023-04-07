class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> odd;
    vector<int> even;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(i % 2 == 0) even.push_back(nums.at(i));
        else odd.push_back(nums.at(i));
    }
    sort(odd.begin(), odd.end(), [](int a, int b){return b <= a;});
    sort(even.begin(), even.end());

    vector<int> res;
    int cnt_e = 0;
    int cnt_o = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(i % 2 == 0) res.push_back(even.at(cnt_e++));
        else res.push_back(odd.at(cnt_o++));
    }
    return res;



    }
};

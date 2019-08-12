class Solution {
public:
    
    
    vector<int> merge(const vector<int>& A, const vector<int>& B)
    {
        int a = 0;
        int b = 0;
        vector<int> c;
        while(a < A.size() && b < B.size())
        {
            if(A.at(a) < B.at(b))
            {
                c.push_back(A.at(a++));
            }
            else
            {
                c.push_back(B.at(b++));
            }
        }
        if(a < A.size())
        {
            c.insert(c.end(), A.begin() + a, A.end());
        }
        else
        {
            c.insert(c.end(), B.begin() + b, B.end());
        }
        return c;
        
    }
    
    
    const vector<int> sort(vector<int>& v)
    {
        if(v.size() == 1) return v;
        else
        {
            int mid = v.size() / 2;
            vector<int> a;
            vector<int> b;
            a.insert(a.begin(), v.begin(), v.begin()+mid);
            b.insert(b.begin(), v.begin()+mid, v.end());
            return merge(sort(a), sort(b));
        }
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        return sort(nums);
    }
};

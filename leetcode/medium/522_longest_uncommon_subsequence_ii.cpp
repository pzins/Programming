class Solution {
public:
    static bool compare(string &s1,string &s2)
    {
        return s1.size() > s2.size();
    }
    bool isSubsequence(string a, string b)
    {
        if(a.size() > b.size()) return false;
        int it = 0;
        for(int i = 0; i < a.size(); ++i)
        {
            while(it < b.size() && a[i] != b[it]) it++;
            if(it >= b.size()) return false;
            it++;
        }
        return true;
    }

    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), compare);
        
        for(int i = 0; i < strs.size(); ++i)
        {
            int ok = true;
            for(int j = 0; j < strs.size(); ++j)
            {
                if(i != j)
                {
                    bool res = isSubsequence(strs[i], strs[j]);
                    if(res) ok = false;
                }
            }
            if(ok) return strs[i].size();
        }
        return -1;
    }
};

class Solution {
public:
    
    
    int get_nb(string& s)
    {
        int r = 0;
        for(auto& i : s)
        {
            if(i == '1') r++;
        }
        return r;
        
    }
    
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int curr = 0;
        for(int i = 0; i < bank.size(); ++i)
        {
            int nb = get_nb(bank.at(i));
            if(nb > 0)
            {
                res += curr * nb;
                curr = nb;
            }
        }
        return res;        
    }
};

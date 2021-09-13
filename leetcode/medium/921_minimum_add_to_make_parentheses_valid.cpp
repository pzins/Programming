class Solution {
public:
     
    int minAddToMakeValid(string s) {
        stack<int> pile;
        int res = 0;
        for(auto& i : s)
        {
            if(i == '(')
            {
                pile.push('(');
            }
            else
            {
                if(pile.size() > 0)
                {
                    pile.pop();
                }
                else
                {
                    res++;
                }
            }
        }
        return res + pile.size();
        
        
    }
};

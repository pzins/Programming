class Solution {
public:
    int secondHighest(string s) {
        set<int> v;
        for(int i = 0; i < s.size(); ++i)
        {
            if(isdigit(s.at(i)))
            {
                v.insert(int(s.at(i)) - int('0'));
            }
        }
        
        if(v.size() < 2) return -1;
        cout << *v.begin() << endl;

        return *(prev(v.end(), 2));
    }
};

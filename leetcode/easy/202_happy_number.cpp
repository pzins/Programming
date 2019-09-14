class Solution {
public:
    bool isHappy(int n) {
        set<int> v;
        while(true)
        {
            if(v.find(n) != v.end()) return false;
            v.insert(n);
            stringstream ss;
            ss << n;
            string str = ss.str();
            int tmp = 0;
            for(int i = 0; i < str.size(); ++i)
            {
                int ol = int(str.at(i)) - '0';
                tmp += ol * ol;
            }
            if(tmp == 1) return true;
            n = tmp;
        }
        return false;
    }
};

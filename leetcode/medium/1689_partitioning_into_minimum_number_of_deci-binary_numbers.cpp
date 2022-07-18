class Solution {
public:
    int minPartitions(string n) {
        int m = 0;
        for(int i = 0; i < n.size(); ++i)
        {
            if(int(n[i]) > m) m = int(n[i]);
        }
        return m-48;
    }
};

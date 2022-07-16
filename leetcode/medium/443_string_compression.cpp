class Solution {
public:
    int compress(vector<char>& c) {
        if(c.size() == 1) {
            return c.size();
        }
        
        
        
        int curr = 0;
        int wr = 0;
        int next = curr + 1;
        bool stop = false;
        while(true) {
            
            while(next < c.size() && c[next] == c[curr]) next++;
            if(next == c.size()) {
                stop = true;
            }
            if(next == (curr + 1))
            {
                c[wr++] = c[curr];
            }
            else
            {
                c[wr++] = c[curr];
                                    
                stringstream ss;
                ss << next - curr;
                string st;
                ss >> st;
                for(auto i : st)
                {
                    c[wr++] = i;
                }
            }
            curr = next++;
            if(stop) break;
        }
        return wr;
    }
};

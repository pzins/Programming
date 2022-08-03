class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int, greater<string>> m;
        for(auto& s : senders) m[s] = 0;
        
        for(int i = 0; i < messages.size(); ++i)
        {
            int r = std::count(messages.at(i).begin(), messages.at(i).end(), ' ');
            m[senders.at(i)] += r+1;
        }
        
        string res;
        int max = 0;
        for(auto& i : m)
        {
            if(i.second > max)
            {
                res = i.first;
                max =  i.second;
            }
        }
        return res;

    }
};

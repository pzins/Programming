class Solution {
public:
    string arrangeWords(string text) {
        vector<vector<string>> v(10000);
        int i = 0;
        while(i < text.size()) {
            string w = "";
            while(i < text.size() && text.at(i) != ' '){
                char c = text.at(i);
                if(int(c) < 97)
                    c = char(int(c) + 32);
                w+=c;
                i++;
            }
            v[w.size()].push_back(w);
            if(i == text.size()) break;
            while(i < text.size() && text.at(i) == ' ') {i++; cout << i << endl;}
            if(i == text.size()) break;
        }
        cout << "45fgdfg" << endl;
        string res = "";
        for(auto& i : v)
        {
            for(auto& j : i)
            {
                if(res != "") res += " ";

                res += j;
            }
        }
        res[0] = char(int(res[0]) - 32);
        return res;
    }
};

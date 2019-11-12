class Solution {
public:
    int dayOfYear(string date) {
        vector<int> months {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> cont;
        size_t current, previous = 0;
        current = date.find('-');
        while (current != std::string::npos) {
            cont.push_back(stoi(date.substr(previous, current - previous)));
            previous = current + 1;
            current = date.find('-', previous);
        }
        cont.push_back(stoi(date.substr(previous, current - previous)));
        int res = 0;
        for(int i = 0; i < cont.at(1)-1; ++i)
        {
            res += months.at(i);
        }
        res += cont.at(2);
        
        int y = cont.at(0);
        if(cont.at(1) == 2 && cont.at(2) == 29) return res;
        if(cont.at(1) <= 2) return res;
        if(y % 4 != 0) return res;
        else if(y % 100 != 0) return res + 1;
        else if(y % 400 != 0) return res;
        else return res + 1;
    }
};

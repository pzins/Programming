class Solution {
public:
    long long smallestNumber(long long num) {
        bool is_neg = (num<0);
        if(is_neg) num *= -1;

        string nb = std::to_string(num);
        vector<int> v;
        for(int i = 0; i < nb.size(); ++i)
        {
            v.push_back(int(nb.at(i)) - 48);
        }
        if(is_neg)
            sort(v.begin(), v.end(), [](int a, int b){return a >= b;});
        else
            sort(v.begin(), v.end());



        int begin = 0;
        while(begin < v.size() && v.at(begin) == 0) begin++;
        
        if(begin != 0 && begin < v.size())
        {
            v[0] = v.at(begin);
            v[begin] = 0;
        }

        long long res = 0;
        for(int i = 0; i < v.size(); ++i)
        {

            res += v.at(i) * pow(10, v.size()-i-1);
        }
        if(is_neg) res *= -1;
        return res;        
    }
};

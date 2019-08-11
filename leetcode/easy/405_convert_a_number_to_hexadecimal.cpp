#include <bitset>

class Solution {
public:
    
    string hexa(int n)
    {
        if(n >= 0 && n < 10) return to_string(n);
        if(n == 10) return "a";
        else if(n == 11) return "b";
        else if(n == 12) return "c";
        else if(n == 13) return "d";
        else if(n == 14) return "e";
        else return "f";
    }
    
    string convert(int num)
    {
        string res = "";
        int div = 0;
        int rest = 0;
        vector<int> v;
        do
        {
            div = num / 16;
            rest = num % 16;
            num = div;
            v.push_back(rest);
        } while(div > 0);
        for(int i = v.size() - 1; i >= 0; i--)
        {
            res += hexa(v.at(i));
        }
        return res;
    }
    
    string toHex(int num) {
        if(num == 0) return "0";
        else if(num > 0)
        {
            return convert(num);
        }
        else
        {  
            if(num == -2147483648) return "80000000";
            std::bitset<32> bitset(-1*(num));
            bitset.flip();
            int carry = 1;
            string tmp = bitset.to_string();
            for(int i = tmp.size() - 1; i >= 0; i--)
            {
                int t = int(tmp.at(i)) - 48 + carry;
                if(t == 0) break;
                if(t == 1)
                {
                    tmp.at(i) = '1';
                    break;
                }
                else
                    tmp.at(i) = '0';
            }
            string res = "";
            for(int p = 0; p < 8; ++p)
            {
                std::bitset<4> b;
                int cnt = 3;
                for(int t = p*4; t < (p+1)*4; ++t)
                {
                    if(tmp.at(t) == '1')
                        b.set(cnt, 1);
                    else
                        b.set(cnt, 0);
                    cnt--;
                }
                res += hexa(b.to_ulong());
            }
            return res;
        }
        
        return "0";
    }
};

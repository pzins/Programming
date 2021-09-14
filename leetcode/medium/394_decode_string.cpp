class Solution {
public:
    
    string fct(string s)
    {
        cout << ">>> " << s << endl;
        if(s.size() == 0) return "";
        int i = 0;
        string res = "";
        while(i < s.size())
        {
            while(isalpha(s[i]))
            {
                res += s[i++];
            }
            if(i >= s.size()) return res;

            int j = i;
            while(s[j] != '[') j++;

            string st = s.substr(i, j-i);      
            cout << "STOI IN " << st << endl;
            int mult = stoi(st);
            i = j+1;
            j = i;
            cout << i << "  " << j << endl;
            
            
            stack<int> stack;
            while(true)
            {
                if(s[j] == '[')
                    stack.push(1);
                if(s[j] == ']')
                {
                    if(stack.size() > 0) stack.pop();
                    else break;
                }
                j++;
            }
            cout << s[i] << " " << s[j] << endl;

            for(int k = 0; k < mult; ++k)
            {
                res += fct(s.substr(i, j-i));
            }
            j++;
            i = j;
        }
        
        return res;
    }
    
    string decodeString(string s) {
        int i = 0;
        string res = "";
        res = fct(s);
        return res;
    }
};

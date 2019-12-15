#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    
    
    for(int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;
        
        char t[3] = {'a', 'b', 'c'};
        string res = "";
        int cnt = 0;
        bool err = false;
        
        for(int j = 0; j < s.size(); ++j)
        {
            if(s.at(j) == 'a')
            {
                cnt = 1;
                res += s.at(j);
            }
            else if(s.at(j) == 'b')
            {
                cnt = 2;
                res += s.at(j);
            }
            else if(s.at(j) == 'c')
            {
                cnt = 0;
                res += s.at(j);
            }
            
            if(s.at(j) == '?')
            {
                if(j+1 >= s.size())
                {
                    res += t[cnt];
                }
                else if(s.at(j+1) != t[cnt])
                {
                    res += t[cnt];
                    cnt = (cnt + 1) % 3;
                }
                else
                {
                    cnt = (cnt + 1) % 3;
                    res += t[cnt];
                }
            }
            
            int ss = res.size();
            if(ss > 1 && res.at(ss - 1) == res.at(ss - 2))
            {
                err = true;
                break;
            }
                
        }
        
        if(err)
        {
            cout<<"-1"<<endl;
            continue;
        }
        cout<<res<<endl;
    }
}

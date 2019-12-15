#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nb;
    cin >> nb;
    for(int i = 1; i <= nb; ++i)
    {
        int n;
        cin >> n;
        string s = to_string(n);
        int res = 9 * (s.size() - 1);

        int a = 0;
        if(s.size() > 1)
        {
            if((int(s.at(0))-48) < (int(s.at(1))-48))
            {
                a += int(s.at(0))-48;
            }
            else if((int(s.at(0))-48) > (int(s.at(1))-48))
            {
                a += int(s.at(0))-48 - 1;
            }
            else
            {
                a += int(s.at(0))-48 - 1;
                string g="";
                string h="";
                for(int l = 0; l < s.size()-1; ++l)
                {
                    g += s.at(0);
                    h += s.at(l+1);
                }
                int ol = stoi(g);
                int lo = stoi(h);
                if(ol <= lo)
                    a++;
            }
        }          
            
        else
            res += (int(s.at(0))-48);
        cout << res + a << endl;
    }
}
        
#include <iostream>
#include <bits/stdc++.h>
    
using namespace std;
    
int main()
{
    int nb;
    cin >> nb;
    for(int i = 0; i < nb; ++i)
    {
        int p;
        cin >> p;
        map<int, vector<int>> g;
        for(int j = 0; j < p; ++j)
        {
            int r, c;
            cin >> c >> r;
            if(g.find(c) != g.end())
            {
                g[c].push_back(r);    
            }
            else
            {
                g[c] = {r};
            }
            
        }
        int r = 0;
        int c = 0;
        int cnt = 0;
        string res = "";
        bool no = false;
        while(cnt < p)
        {
            if(g.find(c) == g.end())
            {
                res += "R";
                c++;
            }
            else
            {
                int max = *max_element(g[c].begin(), g[c].end());
                int min = *min_element(g[c].begin(), g[c].end());
                if(min < r)
                {
                    cout << "NO\n";
                    no = true;
                    break;
                }
                cnt += g[c].size();
                while(r < max)
                {
                    res += "U";
                    r++;
                }
                if(cnt < p)
                {
                    res += "R";
                    c++;
                }
            }
        }
        if(!no)
            cout << "YES\n" << res << "\n";
    }
}

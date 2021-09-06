
#include <iostream>
#include <bits/stdc++.h>
using ll =  long long;

using namespace std;
 
int main()
{
    int nb, m;
    cin >> nb;

    for(int i = 0; i < nb; ++i)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a;
        vector<int> b;
        for(int j = 0; j < n; ++j)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int j = 0; j < m; ++j)
        {
            int tmp;
            cin >> tmp;
            b.push_back(tmp);
        }
        reverse(a.begin(), a.end());
        //cout << "~ " ; for(auto l : a)cout << l << " ";cout << endl;
        
        int res = 0;
        for(int k = 0; k < b.size(); ++k)
        {
            int s = a.size() - 1;
            int res2 = 0;
            map<int, int> m;
            // cout << "=== " ; for(auto l : a)cout << l << " ";cout << endl;

            while(a.at(s) != b.at(k))
            {
                m[a.at(s)] = a.at(s);
                s--;
                res++;
                res2++;
            }
            swap(a.at(s), a.at(a.size()-1));
            a.pop_back();
            // cout << "## " ; for(auto l : a)cout << l << " ";cout << endl;
            res++;
            if(k == b.size()-1) break;
            res+=res2;
            // cout << "&& " << res << endl;
            s = a.size() - 1;
            for(int r = k+1; r < b.size(); ++r)
            {
                if(m.find(b.at(r)) != m.end())
                {
                    a.at(s) = m[b.at(r)];
                    m[b.at(r)] = -1;
                    s--;
                }
            }
            for(auto p : m)
            {
                if(p.second != -1)
                {
                    a.at(s) = p.second;
                    s--;
                }
            }
            
        }
        cout << res << endl;
        
    }
}
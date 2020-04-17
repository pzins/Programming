
#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int nb, m;
    cin >> nb >> m;


    map<int, int> a;
    map<int, int> b;
    
    for(int i = 0; i < nb; ++i)
    {
        int tmp;
        cin >> tmp;
        if(a.find(tmp) != a.end())
        {
            a[tmp]++;
        }
        else
        {
            a[tmp] = 1;
        }
    }
    for(int i = 0; i < nb; ++i)
    {
        int tmp;
        cin >> tmp;
        if(b.find(tmp) != b.end())
        {
            b[tmp]++;
        }
        else
        {
            b[tmp] = 1;
        }
    }
    int o = -1;
    for(int res = 0; res < m; ++res)
    {
        bool ok = true;
        for(auto it = b.begin(); it != b.end(); it++)
        {
            int i = it->first;
            int elem = it->second;
            int index = i - res;
    
            if(res != 0 && index < 0)
                index = m + index;
            else if (res == 0)
                index = i;
            //cout << "# " << res << " " << i << " " << index << endl;
            if(a.find(index) == a.end() || a.at(index) != elem)
            {
                ok = false;
                break;
            }
        }
        if(ok == true)
        {
            o = res;
            break;
        }
    }
    cout << o << endl;
}
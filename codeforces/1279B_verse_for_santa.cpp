
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
        int n;
        ll s;
        cin >> n >> s;
        vector<ll> v;
        for(int j = 0; j < n; ++j)
        {
            ll tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        
        int idx = 0;
        int ol = 0;
        ll m = 0;
        int midx = 0;
        while(idx < v.size())
        {
            ll tmp = v.at(idx);
            if(ol + tmp > s) break;
            ol += tmp;
            if(m < tmp)
            { 
                m = tmp; 
                midx = idx;
            }
            idx++;
        }
 
        //cout << idx << "*** " << ol << " "<< m << " " << midx << endl;
        
 
        if(idx == v.size())
        {
            cout << 0 << endl;
        }
        
        else if(m > v.at(idx))
        {
            cout <<  midx + 1 << endl;
        }
        else
        {
            cout << idx+1 << endl;
        }
        
        
        
        
        
        
    }
}

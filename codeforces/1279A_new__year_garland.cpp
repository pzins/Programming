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
        vector<ll> v;
        ll r,g,b;
        cin >> r >> g >> b;
        v.push_back(r);
        v.push_back(g);
        v.push_back(b);
        sort(v.begin(), v.end());
        if((v.at(0) + v.at(1)) <= v.at(2) - 2)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}

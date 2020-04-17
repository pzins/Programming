#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long int> a;
    for(int i = 0; i < n; ++i)
    {
        unsigned long long tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    if (n <= m)
    {
        unsigned long long res = 1;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                res = (res * abs(a[i] - a[j])) % m;
            }
        }
        cout << res % m << endl;
    }
    else
    {
        cout << 0 << endl;
    }
 
    return 0;
}


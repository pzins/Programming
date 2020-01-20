#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
 
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> r1(n+1);
    vector<int> r2(n+1);
    int bloc = 0;
    int r, c;
    F(tt, q)
    {
        cin >> r >> c;
        if(r == 1)
        {
            if(r1.at(c) == 1)
            {
                r1.at(c) = 0;
                if(r2.at(c) == 1) bloc--;
                if(c+1 <= n && r2.at(c+1) == 1) bloc--;
                if(c-1 >= 0 && r2.at(c-1) == 1) bloc--;
            }
            else
            {
                r1.at(c) = 1;
                if(r2.at(c) == 1) bloc++;
                if(c+1 <= n && r2.at(c+1) == 1) bloc++;
                if(c-1 >= 0 && r2.at(c-1) == 1) bloc++;
            }
        }
        else
        {
            if(r2.at(c) == 1)
            {
                r2.at(c) = 0;
                if(r1.at(c) == 1) bloc--;
                if(c+1 <= n && r1.at(c+1) == 1) bloc--;
                if(c-1 >= 0 && r1.at(c-1) == 1) bloc--;
            }
            else
            {
                r2.at(c) = 1;
                if(r1.at(c) == 1) bloc++;
                if(c+1 <= n && r1.at(c+1) == 1) bloc++;
                if(c-1 >= 0 && r1.at(c-1) == 1) bloc++;
            }
        }
        if(bloc == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

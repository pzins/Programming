
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
        int a, b, c, ra;
        cin >> a >> b >> c >> ra;
        
        
        if(a > b)
        {
            int tmp = b;
            b =  a;
            a = tmp;
        }
        int res = -1;
        int r = c + ra;
        int l = c - ra;
        
        if((l <= a && r <= a) || (r >= b && l >= b))
        {
            res = b-a;
        }
        else if(l >= a && r <= b)
        {
            res = l-a + b-r;
        }
        else if(l <= a && r >= b)
        {
            res = 0;
        }
        else if(l <= a && r <= b)
        {
            res = b - r;
        }
        else if(r >= b && l >= a)
        {
            res = l - a;
        }
        cout << res << endl;        
        
    }
    
}

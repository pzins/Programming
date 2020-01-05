
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
        cin >> n;
        bool started= false;
        int cnt = 0;
        int maxi = 0;
        for(int j = 0; j < n; ++j)
        {
            char tmp;
            cin >> tmp;
            if(started)
            {
                if(tmp == 'P')
                {
                    cnt++;
                }
                else
                {
                    if(cnt > maxi) maxi = cnt;
                    cnt = 0;
                }
            }
            else if(tmp == 'A')
            {
                started = true;
            }
        }
        
        cout << max(cnt, maxi) << endl;
    }
}

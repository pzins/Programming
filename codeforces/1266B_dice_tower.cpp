#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nb;
    cin >> nb;

    for(int i = 1; i <= nb; ++i)
    {
        long long n;
        cin >> n;
        if(n < 15) cout << "NO" << endl;
        else
        {
            bool ok = false;
            for(int r = 1; r <= 6; ++r)
            {
                //if(std::fmod((n - 21 + r), 14) == 0)
                if((n - 21 + r) % 14 == 0)
                {
                    ok = true;
                    break;
                }
            }
            if(ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}


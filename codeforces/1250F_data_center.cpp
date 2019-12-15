#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nb;
    cin >> nb;
    for(int i = 1; i <= nb; ++i)
    {
        if(nb % i == 0)
        {
            if( nb/i <= i )
            {
                cout << 2 * (i + nb/i) << endl;
                break;
            }
        }
    }
}

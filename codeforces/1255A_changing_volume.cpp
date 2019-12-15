#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int i = 0; i < t; ++i)
    {
        int a;
        int b;
        cin >> a >> b;
        
        int diff = abs(a - b);

        if(diff == 0)
        {
            cout << 0 << endl;
        }
        else if(diff == 1)
        {
            cout << 1 << endl;
        }
        else if(diff < 5)
        {
            cout << int(diff/2) + diff%2 << endl;
        }
        else
        {
            int q = int(diff / 5);
            if(b < a && a - 5 * q < 0)
                q--;
            diff = abs(diff - q * 5);
            cout << diff%2 + int(diff / 2) + q << endl;
        }
       
    }
}
        

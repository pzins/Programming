#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
using ll = long long;
 
int main()
{
    
    int n;
    cin >> n;
    while(n--)
    {
        double n, d;
        cin >> n >> d;
        bool ok = false;
        for(int i = 0; i < n; ++i)
        {
            int res = i + ceil(d/(i+1));
            if(res <= n)
            {
                ok = true;
                break;
            }
        }
        if(ok)
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }
}

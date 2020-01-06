
#include <iostream>
#include <bits/stdc++.h>
using ll =  long long;

using namespace std;
 
int main()
{
    int n;
    cin >> n;
    for(int j = 0; j < n; ++j)
    {
        int n, k;
        cin >> n >> k;
        int reste = n % k;
        int d = n / k;
        cout << d * k + min(int(floor(k/2)), reste) << endl;
    }
}

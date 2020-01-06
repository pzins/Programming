
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
        int h, m;
        cin >> h >> m;
        cout << 60*(23-h) + 60-m << endl;
    }
}

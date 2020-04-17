#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int tmp;
        for(int i = 0; i < n; ++i)
        {
            cin >> tmp;
            
            v.push_back(tmp);
        }
        std::sort(v.begin(), v.end(), std::greater<int>());
        for(auto a : v)
        cout << a << " ";
        cout << endl;
        
    }
 
    return 0;
}

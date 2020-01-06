
#include <iostream>
#include <bits/stdc++.h>
using ll =  long long;

using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> vn, vm;
    string tmp;
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp;
        vn.push_back(tmp);
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> tmp;
        vm.push_back(tmp);
    }
    int q;
    cin >> q;
    for(int k = 0; k < q; ++k)
    {
        int a;
        cin >> a;
        cout << vn.at((a-1) % vn.size()) + vm.at((a-1) % vm.size()) << endl;
    }
}

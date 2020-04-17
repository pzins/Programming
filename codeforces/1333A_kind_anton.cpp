#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
using ll = long long int;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        vector<ll> b(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool minus = false;
        bool plus = false;
        bool ok = true;
        for(int i = 0; i < n; ++i)
        {
            if(a[i] != b[i] && !minus && !plus) ok = false;
            else if(a[i] < b[i] && !plus) ok = false;
            else if(a[i] > b[i] && !minus) ok = false;
            if(a[i] == 1)
                plus = true;
            if(a[i] == -1)
                minus = true;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
 
 

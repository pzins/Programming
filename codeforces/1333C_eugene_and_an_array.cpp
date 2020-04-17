#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <fstream>
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
void print(vector<ll>& v)
{
    cout << "## ";
    for(auto& a : v)
        cout << a << " ";
    cout << endl;
    cout << endl;
}
 
int main()
{
    ull n;
    cin >> n;
    vector<ll> a(n, 0);
    vector<ll> cumu(n, 0);
    bool only_zero = true;
    bool only_neg = true;
    bool only_pos = true;
 
    // ifstream myfile ("a");
 
 
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        // myfile >> a[i];
        if(a[i] != 0) only_zero = false;
        if(a[i] <= 0) only_pos = false;
        if(a[i] >= 0) only_neg = false;
        if(i == 0) cumu[i] = a[i];
        else cumu[i] = a[i] + cumu[i - 1];
        // cout << "$$" << i << endl;
    }
    // cout << "--------------" << endl;
    if(only_zero) cout << 0 << endl;
    else if(only_pos || only_neg) cout << n*(n+1)/2 << endl;
    else
    {
        unordered_map<ll, ull> m;
        m[0] = -1;
        ull curr = 0;
        ull res = 0;
        for(int i = 0; i < n; ++i)
        {
            auto ol = m.find(cumu[i]);
            if(ol != m.end())
            {
                curr = max(ol->second + 2, curr);
            }
            m[cumu[i]] = i;
            res += i - curr + 1;
        }
        cout << res << endl;
    }
}

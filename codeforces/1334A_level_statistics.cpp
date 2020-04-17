// This is just a template solution used as initial script
#include <bits/stdc++.h> 
#include <stdlib.h>     /* abs */
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <map>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
 
#define INF std::numeric_limits<int>::max()
#define LLINF std::numeric_limits<long long>::max()
 
#define F(i, n) for (ll i = 0; i < n; ++i)
 
#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl;
 
template <typename T, typename A>
int arg_max(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
}
 
template <typename T, typename A>
int arg_min(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), min_element(vec.begin(), vec.end())));
}
 
vector<int> binary2(ll x)
{
	vector<int> res;
	while (x > 0)
	{
		res.push_back(x % 2);
		x >>= 1;
	}
	return res;
}
 
void primeFactors(vector<int>& v, int n)
{
    while (n % 2 == 0) {v.push_back(2);n = n/2;}
    for (int i = 3; i <= sqrt(n); i = i + 2) {while (n % i == 0){ v.push_back(i); n = n/i;}}
    if (n > 2) v.push_back(n);
}
 
 
int main()
{
    ll tt;
	cin >> tt;
	F(tti, tt)
    {
        int n;
        cin >> n;
        int maxp = -1;
        int maxc = -1;
        bool ok = true;
        F(i, n)
        {
            int p = 0;
            int c = 0;
            cin >> p >> c;
            if(maxp == -1 && maxc == -1) 
            {
                maxp = p;
                maxc = c;
            }
            if(p < maxp || c < maxc)
            {
                ok = false;
                // break;
            }
            if(c > p)
            {
                ok = false;
                // break;
            }
            if(c-maxc > p-maxp)
            {
                ok = false;
                // break;
            }
            
            if(maxp < p) maxp = p;
            if(maxc < c) maxc = c;
 
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
 
 
 
    }
    return 0;
}

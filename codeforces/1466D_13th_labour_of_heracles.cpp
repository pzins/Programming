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

using vi = vector<int>;
using pi = pair<int,int>;

#define INF std::numeric_limits<int>::max()
#define LLINF std::numeric_limits<long long>::max()

#define F(i, n) for (ll i = 0; i < n; ++i)
#define FF(i, start, n) for (ll i = start; i < n; ++i)
 
#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl;

#define VVPRINT(name, v) \
    cout << name << " : " << endl; \
    for (auto& e : v) { \
        for (auto& k : e) { \
            cout << k << " "; \
        } \
        cout << endl; \
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

// vector<pair<int, int>> v;
// sort(v.begin(), v.end(), [](auto const& a, auto const& b) {
//     return a.second > b.second;
// });


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll tt;
	cin >> tt;
	F(tti, tt)
    {
        ll n;
        cin >> n;
        ll tot = 0;
        vector<ll> w(n, 0);
        F(i, n) {
            cin >> w[i];
            tot += w[i];
        }
        vector<ll> res{tot};
        vector<ll> neigh(n, 0);
        F(i, n-1)
        {
            ll a, b;
            cin >> a >> b;
            neigh[a-1]++;
            neigh[b-1]++;
        }
        vector<ll> sp(n, 0);
        F(i, n)
        {
            sp[i] = neigh[i] - 1;
        }
        vector<int> id(n, 0);
        F(i, n) id[i] = i;
        sort(id.begin(), id.end(), [&w](int a, int b){return w[a]>w[b];});
        


        int k = 0;
        for(ll i = 1; i < n-1; ++i)
        {
            while(k<id.size() && sp[id[k]] == 0)
                k++;

            
            if(sp[id[k]] > 0)
            {
                sp[id[k]]--;
                res.push_back(res.at(res.size()-1) + w[id[k]]);
            }
            else
            {
                res.push_back(res.at(res.size()-1));
                
            }
            
        }

        for(auto a : res)
        {
            cout << a << " ";
        }
        cout << endl;



    }
    return 0;
}   
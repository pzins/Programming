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
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll tt;
	cin >> tt;
	F(tti, tt)
    {
        vector<vector<int>> pos{{0,0}, {1, 4}, {2, 8}, 
                                {3, 1}, {4, 5}, {5, 6}, 
                                {6, 2}, {7, 3}, {8, 7}};
        F(i, 9)
        {
            string tmp;
            cin >> tmp;
            int a = tmp[pos[i][1]] - '1';
            a++;
            a = a % 9 ;
            tmp[pos[i][1]] = '1' + a;
            cout << tmp << endl;
        }

    }
    return 0;
}

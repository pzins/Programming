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


struct mystruct
{
    int somme;
    int freq;
};


bool comp(const mystruct &a, const mystruct &b)
{
    return a.freq > b.freq;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll tt;
	cin >> tt;
	F(tti, tt)
    {
        int n, k;
        cin >> n >> k;
        vi v(n, 0);
        F(i, n) cin >> v[i];

        map<int, int> m;
        vector<mystruct> arr;
        F(i, n/2)
        {
            int som = v[i] + v[n-1-i];
            if(m.find(som) == m.end())
            {
                m[som] = 1;
            }
            else
            {
                m[som]++;
            }
        }
        for(auto& a : m)
        {
            mystruct tmp;
            tmp.somme = a.first;
            tmp.freq = a.second;
            arr.push_back(tmp);
        }
        sort(arr.begin(), arr.end(), comp);
        // for(auto& a : arr)
        // {
        //     cout << "##   " << a.somme << " " << a.freq << endl;
        // }
        int res = n/2;
        F(i, arr.size())
        {
            int tmp = 0;
            bool cont = false;
            F(j, n/2)
            {
                int s = v[j] + v[n-1-j];
                if(s == arr[i].somme)
                {
                    continue;
                }
                else if( (arr[i].somme <= v[j] && arr[i].somme <= v[n-1-j]) || 
                         ( arr[i].somme > v[j]+k && arr[i].somme > v[n-1-j]+k))
                {
                    tmp += 2;
                    cont = true;
                }
                else
                {
                    tmp++;
                }
            }
            res = min(res, tmp);
            if(!cont) break;
        }
        
        cout << res << endl;
    }
    return 0;
}
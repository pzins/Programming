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


int dfs(const vector<vector<int>>& g, vector<int>& dist, vector<int>& remove, 
    int curr, int curr_dist)
{
    int tmp = 0;
    if(dist[curr] == INF)
    {
        dist[curr] = curr_dist;
        for(auto& a : g[curr])
        {
            if(dist[a] == INF)
                tmp += dfs(g, dist, remove, a, curr_dist+1);
        }

    }
    remove[curr] = tmp;
    return tmp+1;
}


int bfs(const vector<vector<int>>& g, vector<int>& dist, int start, int end, 
vector<int>& parent,
vector<vector<int>>& children)
{
	// g is a list of neighbours for each node
    // dist is assumed to be filled with INF
    queue<int> q;
    q.push(start);
    queue<int> d;
    d.push(0);
    while (q.size() > 0)
    {
        auto x = q.front();
        auto dd = d.front();
        q.pop();
        d.pop();

        if (dist[x] == INF)
        {
            dist[x] = dd;
            if (end == x)
                break;

            for (auto e: g[x]) {
                if(dist[e] == INF)
                {
                    children[x].push_back(e);
                    q.push(e);
                    parent[e] = x;
                    d.push(dd+1);
                }
            }
        }
    }
    if (end >= 0 && end < dist.size())
        return dist[end];
    else
        return -1;
}

struct mystruct
{
    int id;
    int depth;
    int remove;
};

bool comp(const mystruct &a, const mystruct &b)
{
    return a.depth-a.remove > b.depth-b.remove;
}


int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    ll tt = 1;
	F(tti, tt)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(0));
        vector<int> parent(n, 0);
        vector<vector<int>> children(n, vector<int>(0));

        F(i, n-1)
        {
            int a,b;
            cin >> a >> b;
            
            // parent[b-1] = a-1;
            v[a-1].push_back(b-1);
            v[b-1].push_back(a-1);
        }


        vector<int> dist(n, INF);
        // bfs(v, dist, 0, -1, parent, children);
        vector<int> remove(n, 0);
        dfs(v, dist, remove, 0, 0);
        // VPRINT("dist", dist);
        // VPRINT("remove", remove);

        // VPRINT("parent", parent);
        // VPRINT("children", children);


        vector<mystruct> vec;
        F(i, dist.size())
        {
            mystruct m;
            m.id = i;
            m.depth = dist[i];
            m.remove = remove[i];
            vec.push_back(m);
        }
        sort(vec.begin(), vec.end(), comp);

        ll res = 0;
        F(i, k)
        {
            res += vec[i].depth - vec[i].remove;
        }
        cout << res << endl;


    }
    return 0;
}

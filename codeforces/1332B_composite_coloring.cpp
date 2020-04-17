#include <iostream>
#include <vector>
#include <numeric>
#include<bits/stdc++.h> 
 
 
using namespace std;
 
bool coprime(int a, int b) { 
    return  __gcd(a, b) == 1;
}
 
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i)
        {
            cin >> v.at(i);
        }
        vector<vector<int>> tmp;
        vector<int> div{2,3,5,7,11,13,17,19,23,29,31};
        map<int, int> color;
        int cur_co = 1;
        for(int i = 0; i < v.size(); ++i)
        {
            for(int j = 0; j <= div.size(); ++j)
            {
                // cout << v.at(i) << " " << j << "  " << v.at(i)%div.at(j) << endl;
                if(v.at(i) % div.at(j) == 0)
                {
                    if(color.find(j) == color.end())
                    {
                        color[j] = cur_co;
                        cur_co++;
                    }
                    res.at(i) = color[j];
                    break;
                }
            }
        }
        cout << cur_co-1 << endl;
        for(auto a : res) cout << a << " ";
        cout << endl;
    }
 
}
 

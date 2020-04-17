#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        bool reverse = false;
        if(m > n){
            reverse = true;
            int tmp = n;
            n = m;
            m = tmp;
        }
        vector<vector<char>> g;
        if(m % 2 == 1)
        {
            for(int i = 0; i < m-1; ++i)
            {
                if(i % 2 == 0)
                {
                    vector<char> tmp(n, 'B');
                    g.push_back(tmp);
                }
                else
                {
                    vector<char> tmp(n, 'W');
                    g.push_back(tmp);
                }
                
            }
            if(n % 2 == 1)
            {
                vector<char> tmp(n, 'B');
                for(int j = 0; j < n; ++j)
                {
                    if(j % 2 == 0)
                        tmp[j] = 'B';
                    else
                        tmp[j] = 'W';
                }
                g.push_back(tmp);
            }
            else
            {
                vector<char> tmp(n, 'B');
                for(int j = 0; j < n; ++j)
                {
                    if(j % 2 == 0)
                        tmp[j] = 'B';
                    else
                        tmp[j] = 'W';
                }
                tmp[tmp.size()-1] = 'W';
                tmp[tmp.size()-3] = 'B';
                tmp[tmp.size()-2] = 'W';
                g.push_back(tmp);
            }
        }
        else
        {
            for(int i = 0; i < m; ++i)
            {
                if(i % 2 == 0)
                {
                    vector<char> tmp(n, 'B');
                    g.push_back(tmp);
                }
                else
                {
                    vector<char> tmp(n, 'W');
                    g.push_back(tmp);
                }
            }
            g[g.size()-2][n-2] = 'W';
            g[g.size()-2][n-1] = 'B';
            g[g.size()-1][n-2] = 'B';
            g[g.size()-1][n-1] = 'B';
        }
        if(!reverse)
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < m; ++j)
                {
                    cout << g[j][i];
                }
                cout << endl;
            }
        }
        else
        {
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    cout << g[i][j];
                }
                cout << endl;
            }
        }
    }
}
 


#include <iostream>
#include <bits/stdc++.h>
using ll =  long long;
 
using namespace std;
 
int main()
{
    int n, k;
    cin >> n >> k;
 
    vector<string> v;
    unordered_map<string, int> m;
    for(int i = 0; i < n; ++i)
    {
        string ss = "";
        for(int j = 0; j < k; ++j)
        {
            char c;
            cin >> c;
            ss+=c;
        }
        m[ss] = i;
        v.push_back(ss);
    }
    
    int cnt = 0;
    
    
    for(int a = 0; a < v.size()-1; a++)
    {
        for(int b = a + 1; b < v.size(); ++b)
        {
            string s = "";
            for(int o = 0; o < k; ++o)
            {
                if(v.at(a).at(o) == v.at(b).at(o)) s+=v.at(a).at(o);
                else if(v.at(a).at(o) == 'S' && v.at(b).at(o) == 'E'
                || v.at(a).at(o) == 'E' && v.at(b).at(o) == 'S')
                {
                    s+='T';
                }
                else if(v.at(a).at(o) == 'S' && v.at(b).at(o) == 'T'||
                v.at(a).at(o) == 'T' && v.at(b).at(o) == 'S')
                {
                    s+='E';
                }
                else if(v.at(a).at(o) == 'T' && v.at(b).at(o) == 'E' ||
                v.at(a).at(o) == 'E' && v.at(b).at(o) == 'T')
                {
                    s+='S';
                }
            }
            if(m.find(s) != m.end() && m[s] > b)
            {
                cnt++;
                //cout << "cnt " << cnt << " " <<  v.at(a) << " " << v.at(b) << " " << s << endl;
            }
        }
    }
    
    cout << cnt << endl;
    
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nb;
    cin >> nb;
    for(int i = 1; i <= nb; ++i)
    {
        int size;
        cin >> size;
        vector<int> v;
        map<int, int> m;
        for(int j = 0; j < size; ++j)
        {
            int tmp;
            cin >> tmp;
            if(tmp % 2 == 0 && tmp != 0)
            {
                if(m.find(tmp) == m.end())
                {
                    m[tmp] = 1;
                    v.push_back(tmp);
                }
            }
        }
        sort(v.begin(), v.end(), greater <>());

        int cnt = 0;
        unordered_map<int, int> mm;
        for(int k = 0; k < v.size(); ++k)
        {
            while(v.at(k) % 2 == 0)
            {
                if(mm.find(v.at(k)) != mm.end())
                    break;
                mm[v.at(k)] = 1;
                v.at(k) /= 2;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
        
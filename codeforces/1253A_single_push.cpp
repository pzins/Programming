#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int i = 0; i < t; ++i)
    {
        int size;
        cin >> size;
        vector<int> a;
        vector<int> b;
        int tmp;
        for(int j = 0; j < size; ++j)
        {
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int j = 0; j < size; ++j)
        {
            cin >> tmp;
            b.push_back(tmp);
        }
        int diff = -1;
        int no = false;
        for(int j = 0; j < a.size(); ++j)
        {
            int val = b.at(j) - a.at(j);
            if(val < 0)
            {
                no = true;
                break;
            }
            else if(val == 0)
            {
                if(diff != -1)
                    diff = -2;
                continue;
            }
            else
            {
                if(diff == -1)
                {
                    diff = val;
                }
                else if(diff != val)
                {
                    no = true;
                    break;
                }
            }
        }
        if(no)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
        

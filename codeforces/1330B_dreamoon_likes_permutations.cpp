#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i)
        {
            cin >> v.at(i);
        }
        vector<int> sol;
        
        
        vector<int> nb(n, 0);
        int curr_max = 0;
        for(int i = 0; i < v.size(); ++i)
        {
            // cout << nb.size() << " " << v.size() << endl;
            // cout << i << " " << v.at(i) << " " << nb.at(v.at(i)-1) << endl;
            if(nb.at(v.at(i)-1) == 1)
            {
                if(curr_max != i-1) break;
                bool good = true;
                vector<int> second(n-i, 1);
                for(int k = i; k < v.size(); ++k)
                {
                    if(v.at(k)-1 >= second.size())
                    {
                        good = false;
                        break;
                    }
                    second.at(v.at(k)-1) = 0;
                }
                if(good == false) break;
                int max = *max_element(second.begin(), second.end());
                if(max != 0) break;
                sol.push_back(i);
                break;
            }
            else
            {
                nb.at(v.at(i)-1) = 1;
                if(v.at(i)-1 > curr_max) curr_max = v.at(i)-1;
                // cout << v.at(i)-1 << endl;
            }
        }
 
        // std::fill(nb.begin(), nb.end(), 0);
        vector<int> nb2(n, 0);
 
        curr_max = 0;
        for(int i = v.size()-1; i >= 0; --i)
        {
            if(nb2.at(v.at(i)-1) == 1)
            {
                // cout << "#" << i << " " << curr_max << " " << n-(i+1)-1<< endl;
                if(curr_max != n-(i+1)-1) break;
                bool good = true;
 
                vector<int> sec(i+1, 1);
                for(int k = i; k >= 0; --k)
                {
                    if(v.at(k)-1 >= sec.size())
                    {
                        good = false;
                        break;
                    }
                    sec.at(v.at(k)-1) = 0;
                }
                if(good == false) break;
                int max = *max_element(sec.begin(), sec.end());
                if(max != 0) break;
                sol.push_back(i+1);
                break;
            }
            else
            {
                nb2.at(v.at(i)-1) = 1;
                if(v.at(i)-1 > curr_max) curr_max = v.at(i)-1;
 
                // cout << v.at(i)-1 << endl;
            }
        }
 
 
        if(sol.size() == 0)
        {
            cout << "0" << endl;
        }
        else
        {
            if(sol.size() == 2 && sol.at(0) == sol.at(1))
            {
                cout << "1" << endl;
                cout << sol.at(0) << " " << n - sol.at(0) << endl;
            }
            else
            {
                cout << sol.size() << endl;
                for(int i = 0; i < sol.size(); ++i)
                {
                    cout << sol.at(i) << " " << n-sol.at(i) << endl;
                }
            }
        }
        
 
    }
 
}

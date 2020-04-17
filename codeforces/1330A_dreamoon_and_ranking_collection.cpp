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
        int n, x;
        cin >> n >> x;
        vector<int> v(n, 0);
        vector<int> res(1000, 0);
        for(int i = 0; i < n; ++i)
        {
            cin >> v.at(i);
            res.at(v.at(i)-1) = 1;
        }
        
        int curr = 0;
        while(x > 0)
        {
            if(res.at(curr) == 0)
            {
                res.at(curr) = 1;
                x--;
            }
            curr++;
        }
        while(res.at(curr) == 1) curr++;
        cout << curr << endl;
    }
 
}

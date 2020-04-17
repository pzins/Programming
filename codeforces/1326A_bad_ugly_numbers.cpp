#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        if(a == 1)
        {
            cout << "-1\n";
        }
        else
        {
            vector<int> v(a, 2);
            v.at(v.size() - 1) = 3;
            long long unsigned s = accumulate(v.begin(), v.end(), 0);
            if(s % 3 == 0)
            {
                v.at(0) = 3;
            }
            for(auto& a : v)
            cout << a;
            cout << "\n";
        }
    }
}

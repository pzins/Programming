#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i)
        cin >> v.at(i);
 
    vector<int> res(v);
    res.at(0) = v.at(0);
    int maxi = res.at(0);
    for(int i = 1; i < v.size(); ++i)
    {
        res.at(i) += maxi;
        if(res.at(i) > maxi) maxi = res.at(i);
    }
    for(auto a : res)
        cout << a << " ";
    cout << endl;
 
}

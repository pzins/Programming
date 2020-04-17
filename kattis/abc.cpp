#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main() {
    vector<int> v(3, 0);
    int m = -1;
    int M = -1;
    for(int i = 0; i < v.size(); ++i)
    {
        cin >> v[i];
        if(v[i] > M || M == -1) M = v[i];
        if(v[i] < m || m == -1) m =  v[i];
    }
    int other = -1;
    for(auto a : v)
    {
        if(a != m && a != M)
        {
            other = a;
            break;
        }
    }
    string res = "";
    string s;
    cin >> s;
    for(int i = 0; i < 3; i++)
    {
        if(s.at(i) == 'A') res += std::to_string(m) + " ";
        else if(s.at(i) == 'B') res += std::to_string(other) + " ";
        else res += to_string(M) + " ";

    }
    cout << res << endl;

    return 0;
}
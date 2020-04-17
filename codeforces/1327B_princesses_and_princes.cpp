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
        int n;
        cin >> n;
        vector<vector<int>> d;
        for(int i = 0; i < n; ++i)
        {
            int s;
            cin >> s;
            vector<int> v(s,0);
            for (int j = 0; j < s; ++j) cin >> v.at(j);
            d.push_back(v);
        }
        vector<int> v(n, 1);
        int save_index = -1;
        for(int i = 0; i < d.size(); ++i)
        {
            bool not_married = true;
            for(int j = 0; j < d.at(i).size(); ++j)
            {
                if(v.at(d.at(i).at(j)-1) == 1)
                {
                    v.at(d.at(i).at(j)-1) = 0;
                    not_married = false;
                    break;
                }
            }
            if(not_married)
            {
                save_index = i;
            }
        }
        if(save_index == -1)
        {
            cout << "OPTIMAL" << endl;
        }
        else
        {
            cout << "IMPROVE" << endl;
            int id = 0;
            for(int k = 0; k < n; ++k)
            {
                if(v.at(k) == 1)
                {
                    id = k;
                    break;
                }
            }
            cout << save_index+1 << " " << id+1 << endl;
        }
        
    }
}
 

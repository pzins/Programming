
#include <iostream>
#include <bits/stdc++.h>
 using ll =  long long;

using namespace std;
 
int main()
{
    int nb, m;
    cin >> nb;

    for(int i = 0; i < nb; ++i)
    {
        int n, p, k;
        cin >> n >> p >> k;
        vector<int> ai;
        for(int j = 0; j < n; ++j)
        {
            int tmp;
            cin >> tmp;
            ai.push_back(tmp);
        }
        sort(ai.begin(), ai.end());
        
        int m1 = 0;
        int m2 = 0;
        
        int mo = p;
        for(int k = 0; k < ai.size(); ++k)
        {
            if(k == 0)
            {
                if(ai.at(k) > mo)
                {
                    break;
                }
                else
                {
                    mo -= ai.at(k);
                    m1++;
                }
            }
            else
            {
                if(ai.at(k) > mo) break;
                else
                {
                    if(k + 1 < ai.size() && ai.at(k+1) <= mo)
                    {
                        m1 += 2;
                        mo -= ai.at(k+1);
                        k++;
                    }
                    else
                    {
                        m1++;
                        mo -= ai.at(k);
                    }
                }
            }
        }
   
        mo = p;
        m2 = 0;
        for(int k = 1; k < ai.size(); ++k)
        {
            if(ai.at(k) > mo)
            {
                if(ai.at(k-1) <= mo)
                {
                    mo -= ai.at(k-1);
                    m2++;
                }
                break;
            }
            else
            {
                mo -= ai.at(k);

                m2 += 2;
                k++;
                // cout << "k=" << k << "mo=" << mo << endl;
            }
        }
        //  cout << m1 << "  " << m2 << endl;
        cout << max(m1, m2) << endl;
    }
}

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
        int n, p, pp, k;
        cin >> n >> pp >> k;
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
        

        int begin = 0;
        for(int o = 0; o < k; ++o)
        {
            if(o > 0)
            {
                begin += ai.at(o-1);
            }
            p = pp;
            p -= begin;
            cout << "begin" << begin << " " << p << "  o  " << o  << endl;
            if(begin > p) break;
            m1 = o;
            int idx = o-1+k;
            cout << "idx=" << idx << "  k=" << k << "   p=" << p<< endl;
            while(idx < n && p>0)
            {
                cout << "ai " << ai.at(idx) << endl;
                if(ai.at(idx) <= p)
                {
                    p -= ai.at(idx);
                    m1 += k;
                    idx += k;
                }
                else
                {
                    break;
                }
            }
            cout<<"ok"<<endl;
            if(idx < n && p >0)
            {
                idx -= k;
                if(idx < 0) idx = 0;
                while(idx >= 0 && p >= 0 && idx < n)
                {
                    if(ai.at(idx) <= p)
                    {
                        m1++;
                        p -= ai.at(idx);
                    }
                    idx++;
                }
            }
            // cout << "m1 " << m1 << endl;
            m2 = max(m1, m2);
        }
        //  cout << m1 << "  " << m2 << endl;
        cout << m2 << endl;
    }
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nb;
    cin >> nb;
    
    for(int p = 0; p < nb; ++p)
    {
        string s;
        cin >> s;
        
        vector<int> letters(26, 0);
        
        int index = 0;
        while(index < s.size())
        {
            int cnt = 1;
            char l = s.at(index);
            while(index + cnt < s.size() && l == s.at(index + cnt)) cnt++;
            if(cnt % 2 == 1)
            {
                letters[l - 'a'] = 1;
            }
            index += cnt;
        }
    
        for(int i = 0; i < 26; ++i)
        {
            if(letters[i] == 1)
                cout << static_cast<char>(i + static_cast<int>('a'));
        }
        cout << endl;
    }
}

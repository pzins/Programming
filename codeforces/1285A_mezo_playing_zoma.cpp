#include<iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    string s;
    cin >> s;
    int mini = 0;
    int maxi = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s.at(i) == 'L') mini--;
        else maxi++;
    }
    cout << maxi-mini+1 << endl;
}

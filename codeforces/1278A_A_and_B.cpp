#include<iostream>

using namespace std;

int main()
{
    int t,a,b,i;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        a = abs(a - b);
        b = 0;
        i = 0;
        while( a > b || (b - a) % 2 != 0)
            b+=++i;
        cout << i << endl;
    }
}

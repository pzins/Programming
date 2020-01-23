#include <iostream>
#include <bits/stdc++.h>
    
using namespace std;
    
    
void primeFactors(int n, vector<int>& v)  
{  
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        //cout << 2 << " ";  
        v.push_back(2);
        n = n/2;  
    }  
    
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            //cout << i << " ";
            v.push_back(i);
            n = n/i;  
        }  
    }  
    
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
    {
        v.push_back(n);
        // cout << n << " ";  
    }
}  
    
    
int main()
{
    int nb;
    cin >> nb;
    for(int m = 0; m < nb; ++m)
    {
        int p;
        cin >> p;
        vector<int> primes;
        primeFactors(p, primes);
        if(primes.size() <= 2) {cout << "NO\n"; continue;}
        
        int cnt = 0;
        int a,b,c = 0;
        a = primes.at(0);
        b = primes.at(1);
        cnt = 2;
        while(cnt < primes.size() && b == a)
        {
            b *= primes.at(cnt);
            cnt++;
        }
        if(a == b || cnt == primes.size())
        {
            cout << "NO\n";
            continue;
        }
        c = primes.at(cnt++);
        while(cnt < primes.size())
        {
            c *= primes.at(cnt);
            cnt++;
        }
        if(b == c || a == c)
            cout << "NO\n";
        else
            cout << "YES\n" << a << " " << b << " " << c << "\n";
    }
}

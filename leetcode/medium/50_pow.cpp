class Solution {
public:
    double myPow(double x, int nn) {
        if(x == 1) return 1;
        if(x == -1 && nn % 2 == 0) return 1;
        if(x == -1 && nn % 2 == 1) return -1;
        if(nn == 0) return 1;
        if(nn == 1) return x;
        if(nn == -1) return 1/x;
        double res = x;
        
        double l = x;
        double n = nn;
        if(n < 0) n *= -1;
        double cnt = 1;

        while(abs(n-cnt) > abs(cnt+cnt-n))
        {
            l *= l;
            cnt += cnt;
        }
        cout<<n<< " " << cnt << l << endl;
        if(n > cnt)
        {
            for(int i = cnt; i < n; ++i)
                l *= x;
        }
        else if(n < cnt)
        {
            for(int i = cnt; i > n; --i)
            {
                l /= x;
            }
        }
        res = l;
        if(nn > 0) return res;
        return 1/res;
    }
};

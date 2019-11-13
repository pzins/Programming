class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int maxi = 0;
        int tmp = 0;
        bool first = true;
        for(int i = 0; i < seats.size(); ++i)
        {
            if(seats.at(i) == 0) tmp++;
            if(seats.at(i) == 1)
            {
                if(!first)
                {
                    if(tmp % 2 == 0)
                    {
                        tmp /= 2;
                    }
                    else
                    {
                        tmp = tmp / 2 + 1;
                    }
                }
                if(tmp > maxi) maxi = tmp;
                tmp = 0;
                first = false;
            }
        }
        if(tmp > maxi) maxi = tmp;
        return maxi;
    }
};

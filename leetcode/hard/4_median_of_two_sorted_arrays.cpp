class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        int mid = (n1.size() + n2.size());
        if(mid == 1)
        {
            if(n1.size() == 0) return n2.front();
            else return n1.front();
        }
        bool odd = false;
        if(mid % 2 == 1)
        {
            odd = true;
            mid = int(mid/2);
        }
        else
        {
            mid /= 2;
            mid--;
        }
            
        int cnt1 = 0;
        int cnt2 = 0;
        // std::cout << mid << std::endl;
        while(1)
        {
            // std::cout << cnt1 << " " << cnt2 << std::endl;
            if(cnt1+cnt2 == mid)
            {
                if(odd)
                {
                    // std::cout << "odd" << std::endl;
                    if(cnt2 >= n2.size() || cnt1 < n1.size() && n1.at(cnt1) <= n2.at(cnt2))
                    {
                        return n1.at(cnt1);
                    }
                    else if(cnt1 >= n1.size() || cnt2 < n2.size() && n2.at(cnt2) <= n1.at(cnt1))
                    {
                        return n2.at(cnt2);
                    }
                }
                else
                {
                    // std::cout << "even " << cnt1 << " " << cnt2 << std::endl;
                    float s = 0;
                    if(cnt2 >= n2.size() || cnt1 < n1.size() && n1.at(cnt1) <= n2.at(cnt2))
                    {
                        // std::cout << "add " << n1.at(cnt1) << std::endl;
                        s += n1.at(cnt1++);
                    }
                    else if(cnt1 >= n1.size() || cnt2 < n2.size() && n2.at(cnt2) <= n1.at(cnt1))
                    {
                        // std::cout << "add " << n2.at(cnt2) << std::endl;
                        s += n2.at(cnt2++);
                    }
                    // std::cout << "even " << cnt1 << " " << cnt2 << std::endl;

                    if(cnt2 >= n2.size() || cnt1 < n1.size() && n1.at(cnt1) <= n2.at(cnt2))
                    {
                        // std::cout << "add " << n1.at(cnt1) << std::endl;
                        s += n1.at(cnt1);
                    }
                    else if(cnt1 >= n1.size() || cnt2 < n2.size() && n2.at(cnt2) <= n1.at(cnt1))
                    {
                        // std::cout << "add " << n2.at(cnt2) << std::endl;
                        s += n2.at(cnt2);
                    }
                    // std::cout << s/2 << std::endl;
                    return s/2;
                }
            }
            else if(cnt2 >= n2.size() || cnt1 < n1.size() && n1.at(cnt1) <= n2.at(cnt2))
            {
                cnt1++;
            }
            else if(cnt1 >= n1.size() || cnt2 < n2.size() && n2.at(cnt2) <= n1.at(cnt1))
            {
                cnt2++;
            }
        }
        
    }
};

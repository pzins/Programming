class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if(x < arr[0])
        {
            res.insert(res.end(), arr.begin(), arr.begin()+k);
        }
        else if(x > arr[arr.size() - 1])
        {
            res.insert(res.end(), arr.end()-k, arr.end());
        } else {
            // auto it = find(arr.begin(), arr.end(), x);
            int l = 0;
            for(int i = 0; i < arr.size()-1; ++i)
            {
                if(arr[i] == x) {
                    l = i;
                    break;
                }
                else if(arr[i+1] == x)
                {
                    l = i+1;
                    break;
                }
                else if(arr[i] < x && arr[i+1] > x)
                {
                    if(abs(arr[i] - x) <= abs(arr[i+1] - x))
                    {
                        l = i;
                    } else {
                        l = i+1;
                    }
                    break;
                }
            }
            //cout << l << endl;
            int r = l;
            res.push_back(arr[l]);
            l--;
            r++;
            cout << "ol" << endl;
            while(res.size() < k)
            {
                //cout << "$ " << arr[l] << " " << arr[r] << endl;
                if(r >= arr.size()) res.push_back(arr[l--]);
                else if(l < 0) res.push_back(arr[r++]);
                else
                {
                    // cout << "comp " << (abs(arr[l]) - x) << " " << (abs(arr[r]) - x) << endl;
                    if(abs(arr[l] - x) <= abs(arr[r] - x)) res.push_back(arr[l--]);
                    else res.push_back(arr[r++]);
                }
                // cout << ":" << res[res.size()-1] << endl;
            }
            sort(res.begin(), res.end());
        }
        return res;
    }
};

class Solution {
public:
    int maxLength(vector<string>& arr) {
        if(arr.size() == 1) return arr[0].size();
        vector<int> letters(26,0);
        cout << letters.size() << endl;
        int res = fct(arr, 0, letters, 0);
        return res;
    }
    
    int fct(vector<string>& arr, int idx, vector<int> letters, int count)
    {
        if(idx >= arr.size()) return count;
              
        int no=0, yes=0;
        no = fct(arr, idx+1, letters, count);
        
        bool ok = true;
        for(auto& a : arr[idx])
        {
            if(letters[int(a) - int('a')] == 1)
            {
                ok = false;
            }
            letters[int(a) - int('a')] = 1;
        }
        if(ok)
        {
            yes = fct(arr, idx+1, letters, count + arr[idx].size());
        }
        return max(no, yes);
    }
};

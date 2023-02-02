class Solution {



public:
    int videoStitching(vector<vector<int>>& clips, int time) {

      
        std::sort(clips.begin(), clips.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) return a[1] >= b[1];
            return a[0] < b[0];
        });

        int cnt = 1;
        int l = clips[0][0];
        int r = clips[0][1];
        if(l != 0) return -1;
        int curr = 0;
        int new_r = r;
        int new_clip = -1;

        while(true)
        {
            cout << curr << " " << l << " " << r << endl;
            new_clip = -1;
            for(int j = 0; j < clips.size(); ++j)
            {
                if(j != curr)
                {
                    if(clips[j][0] > l && clips[j][0] <= r && (clips[j][1] > new_r || new_clip == -1))
                    {
                        new_r = clips[j][1];
                        new_clip = j;
                    }
                }
            }
            if(new_clip == -1) break;
            if(r >= time) break;
            cnt++;
            curr = new_clip;
            l = clips[curr][0];
            r = clips[curr][1];

        }
        if(r < time) return -1;
        return cnt;




    }
};

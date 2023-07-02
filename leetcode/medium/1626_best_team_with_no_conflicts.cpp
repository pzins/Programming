class Solution {
public:

    static bool comp(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.first==b.first) return a.second < b.second;
        return a.first < b.first;
    }

    int fct(int i, int prev, vector<pair<int, int>>& data, vector<vector<int>>& dp)
    {
        if(i >= data.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int pick = INT_MIN;
        if(prev==-1 || 
        (data[i].first > data[prev].first && data[i].second >= data[prev].second) ||
        (data[i].first == data[prev].first) ||
        (data[i].first < data[prev].first && data[i].second < data[prev].second))
        {
            pick = data[i].second + fct(i+1, i, data, dp);
        }
        int nopick = fct(i+1, prev, data, dp);
        return dp[i][prev+1] = max(pick, nopick);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        vector<pair<int, int>> data;
        for(int i = 0; i < n; ++i)
        {
            data.push_back({ages[i], scores[i]});
        }
        sort(data.begin(), data.end(), comp);
        return fct(0, -1, data, dp);
    }
};

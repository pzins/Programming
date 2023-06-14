class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.size();
        
        // Create dp table with one additional row / column
        int dp[length+1][length+1];
        
        // Reverse the initial string
        string r = s;
        reverse(r.begin(), r.end());
        
        // Find the longest common subsequence between the two strings
        for(int i = 0; i < s.size()+1; ++i)
        {
            for(int j = 0; j < r.size()+1; ++j)
            {
                // Fill the first row and column with 0
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                // If elements from the two string (index -1) are equal, add 1 to the top left result
                else if(s[i-1] == r[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                // Otherwise take the max between the result above and on the left
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // The final result is the number computer in the bottom right position in the table
        return dp[length][length];
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int start = 0;

        // Creating boolean table for dynamic programming that store if substring from i to j (dp[i][j]) is a palindrome
        bool dp[length][length];

        // Initialize to false
        memset(dp, 0, sizeof(dp));

        // Initialize substring size 1 as true palindrome
        int max_length = 1;
        for(int i = 0; i < length; ++i)
        {
            dp[i][i] = true;
        }

        // Initialize substring size 2 as true palindrome if it is true
        for(int i = 0; i < length - 1; ++i)
        {
            if(s[i] == s[i+1]) 
            {
                dp[i][i+1] = true;
                start = i;
                max_length = 2;
            }
        }

        // Iterate over possible palindrome size
        for(int k = 3; k <= length; ++k)
        {
            // Iterate over starting point
            for(int i = 0; i < length - k + 1; ++i)
            {
                // Get the index of the end of the substring
                int j = i + k - 1;

                // Check if interior substring is a palindrome and exterior characters are equal. In that case it's a palindrome
                if(dp[i+1][j-1] && s[i] == s[j])
                {
                    dp[i][j] = true;
                    if(k > max_length)
                    {
                        max_length = k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, max_length);

    }
};

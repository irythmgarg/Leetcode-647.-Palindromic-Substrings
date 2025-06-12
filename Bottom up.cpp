class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        bool dp[n][n]; // dp[i][j] will be true if substring s[i..j] is a palindrome
        int ans = 0;   // Count of palindromic substrings

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            ans++; // Count each single character as a palindrome
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans++; // Count two-character palindromes
            } else {
                dp[i][i + 1] = false;
            }
        }

        // Check for substrings of length 3 or more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // End index of current substring

                // Check if s[i..j] is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans++; // Count the current palindromic substring
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return ans; // Return total count of palindromic substrings
    }
};

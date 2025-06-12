class Solution {
public:
    // DP table to store whether substring s[i..j] is a palindrome
    int dp[1001][1001];

    // Helper function to check if a substring s[i..j] is a palindrome
    bool Ispalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;  // Mismatch found, not a palindrome
            i++;
            j--;
        }
        return true;  // All characters matched, it's a palindrome
    }

    // Recursive function to count palindromic substrings starting from index 'i'
    int CountSubstrings(string &s, int i) {
        // Base case: if i exceeds the string length, return 0
        if (i >= s.length())
            return 0;

        int count = 0;

        // Try all substrings starting from index i to end of string
        for (int j = i; j < s.length(); j++) {
            // If the result for s[i..j] is not computed
            if (dp[i][j] == -1) {
                if (Ispalindrome(s, i, j)) {
                    count++;         // Count this palindrome
                    dp[i][j] = 1;    // Mark as palindrome
                } else {
                    dp[i][j] = 0;    // Mark as not a palindrome
                }
            } else {
                // If already computed and it's a palindrome, count it
                if (dp[i][j] == 1)
                    count++;
            }
        }

        // Move to the next starting index
        return count + CountSubstrings(s, i + 1);
    }

    // Main function to be called to count all palindromic substrings in the string
    int countSubstrings(string &s) {
        // Initialize dp table with -1 (means not computed yet)
        memset(dp, -1, sizeof(dp));
        return CountSubstrings(s, 0);  // Start counting from index 0
    }
};

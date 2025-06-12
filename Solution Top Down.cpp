class Solution {
public:
    // DP table to store palindrome results: 
    // dp[i][j] = 1 if s[i..j] is a palindrome, 0 if not, -1 if not yet computed
    int dp[1001][1001];

    // Helper function to check if the substring s[i..j] is a palindrome
    bool Ispalindrome(string &s, int i, int j)
    {
        // Base case: empty or single character substring is a palindrome
        if (i > j) return true;

        // If characters don't match, it's not a palindrome
        if (s[i] != s[j]) return false;

        // If already computed, return cached result
        if (dp[i][j] != -1)
            return dp[i][j];

        // Recursive check for inner substring
        return dp[i][j] = Ispalindrome(s, i + 1, j - 1);
    }

    // Recursive function to count palindromic substrings starting from index i
    int CountSubstrings(string &s, int i)
    {
        // Base case: no substrings left
        if (i >= s.length())
            return 0;

        int count = 0;
        // Try all substrings starting at i
        for (int j = i; j < s.length(); j++)
        {
            // If s[i..j] is palindrome, increment count
            if (Ispalindrome(s, i, j))
                count++;
        }

        // Move to the next starting index
        return count + CountSubstrings(s, i + 1);
    }

    // Main function to count all palindromic substrings in the input string
    int countSubstrings(string &s)
    {
        // Initialize DP array with -1 (meaning uncomputed)
        memset(dp, -1, sizeof(dp));

        // Start the recursive counting from index 0
        return CountSubstrings(s, 0);
    }
};

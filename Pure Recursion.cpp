class Solution {
public:

    // Helper function to check if the substring s[i...j] is a palindrome
    bool Ispalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;  // Mismatch found, not a palindrome
            i++;
            j--;
        }
        return true;  // All characters matched, it's a palindrome
    }

    // Recursive function to count palindromic substrings starting from index 'i'
    int CountSubstrings(string s, int i) {
        // Base case: if index exceeds string length, return 0
        if (i >= s.length())
            return 0;

        int count = 0;

        // Check all substrings starting at index i
        for (int j = i; j < s.length(); j++) {
            if (Ispalindrome(s, i, j)) {
                count++;  // Increment if substring s[i...j] is a palindrome
            }
        }

        // Move to the next starting index and add its result
        return count + CountSubstrings(s, i + 1);
    }

    // Main function to count all palindromic substrings in the string 's'
    int countSubstrings(string s) {
        return CountSubstrings(s, 0);  // Start recursive counting from index 0
    }
};

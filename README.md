# Leetcode-647.-Palindromic-Substrings

# 💎 Palindromic Substrings (Count All Palindromic Subsequences)

This guide explains how to **count all palindromic substrings** in a given string using various approaches including recursion and dynamic programming. 🧵

---

## 📘 Problem Statement

Given a string `s`, return the **total number of palindromic substrings** in it. A substring is a sequence of characters that appears in the same order and is contiguous in the string.

### 💡 Example:

Input: `s = "abc"`
Output: `3`  → {"a", "b", "c"}

Input: `s = "aaa"`
Output: `6`  → {"a", "a", "a", "aa", "aa", "aaa"}

---

## 🌀 Approach 1: Pure Recursion with Memoization (Top-Down) 🔍

### 🧠 Idea:

* Use recursion to explore all substrings starting from every index.
* Use a helper function to check if `s[i..j]` is a palindrome.
* Memoize the results to avoid redundant computation.

### 📦 Code Outline:

```cpp
int dp[1001][1001];

bool Ispalindrome(string &s, int i, int j)
{
    if (i > j) return true;
    if (s[i] != s[j]) return false;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = Ispalindrome(s, i + 1, j - 1);
}

int CountSubstrings(string &s, int i)
{
    if (i >= s.length()) return 0;
    int count = 0;
    for (int j = i; j < s.length(); j++)
        if (Ispalindrome(s, i, j)) count++;
    return count + CountSubstrings(s, i + 1);
}

int countSubstrings(string &s)
{
    memset(dp, -1, sizeof(dp));
    return CountSubstrings(s, 0);
}
```

### ⏱️ Complexity:

* Time: **O(n³)** due to recursion and nested loops
* Space: **O(n²)** for memoization

---

## 📐 Approach 2: Bottom-Up Dynamic Programming (Tabulation)

### 🧠 Idea:

* Create a 2D DP table `dp[i][j]` where each cell stores if `s[i..j]` is a palindrome.
* Use lengths of 1 and 2 as base cases, then expand for substrings of length 3 or more.
* Count all palindromic substrings.

### 📦 Code Outline:

```cpp
int countSubstrings(string s) {
    int n = s.length();
    bool dp[n][n];
    int ans = 0;

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        ans++;
    }

    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = (s[i] == s[i + 1]);
        if (dp[i][i + 1]) ans++;
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            if (dp[i][j]) ans++;
        }
    }

    return ans;
}
```

### ⏱️ Complexity:

* Time: **O(n²)**
* Space: **O(n²)**

---

## 🎯 Final Thoughts

* Recursion + memoization is intuitive but slower.
* Bottom-up DP is efficient and widely used in interviews and contests.

🔁 This problem is a stepping stone to **Longest Palindromic Subsequence**, **Palindrome Partitioning**, and **Dynamic String Matching**.

---

**Made with ❤️ by Ridham Garg**

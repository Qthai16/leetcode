#include <bits/stdc++.h>
using namespace std;

// Given a string s, return the longest palindromic substring in s.
// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

// using two pointers (O(N^2) complexity)
// https://leetcode.com/problems/longest-palindromic-substring/solutions/6141600/video-using-two-pointers-python-javascri-gsz2/

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        int l = start, r = end;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        if (s.size() == 2) return s[0] == s[1] ? s : string{s[0]};
        int longest = INT_MIN;
        pair<int, int> p; // l, r pointer of longest palindrome window
        // maybe using sliding windows
        // increase left
        // decrease right
        // both increase left and decrease right
    }
};
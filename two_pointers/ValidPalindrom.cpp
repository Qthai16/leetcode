#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for (const auto &c: s) {
            if ('A' <= c && c <= 'Z') {
                s2 += c + 32;
            } else if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9')) {
                s2 += c;
            }
        }
        if (s2.empty() || s2.size() == 1) return true;
        int l = 0, r = s2.size() - 1;
        while (l < r) {
            if (s2[l] == s2[r]) {
                l++;
                r--;
                continue;
            }
            return false;
        }
        return true;
    }
};
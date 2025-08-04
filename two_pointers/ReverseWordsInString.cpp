#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // using stack
        if (s.empty() || s.size() == 1) return s;
        stack<char> d;
        string ans;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                while (!d.empty()) {
                    ans += d.top();
                    d.pop();
                }
                if (!ans.empty() && ans[ans.size() - 1] != ' ') ans += ' ';
                continue;
            }
            d.push(s[i]);
        }
        while (!d.empty()) {
            ans += d.top();
            d.pop();
        }
        if (ans[ans.size() - 1] == ' ') ans.pop_back();
        return ans;
    }
    
    string reverseWords(string s) {
        // using two pointers
        if (s.empty() || s.size() == 1) return s;
        string ans;
        int r = s.size() - 1, l = r;
        while (l >= 0) {
            if (s[l] == ' ') {
                if (r != l) {
                    for (auto i = l + 1; i <= r; i++) {
                        ans += s[i];
                    }
                    ans += ' ';
                    r = l;
                }
                r--;
                l--;
                continue;
            }
            l--;
        }
        for (auto i = l + 1; i <= r; i++) {
            ans += s[i];
        }
        while (ans[ans.size() - 1] == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};
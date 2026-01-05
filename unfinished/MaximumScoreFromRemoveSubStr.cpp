#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

// remove "ab" and gain x score
// remove "ba" and gain y score

// y + x + x

// Example 1:

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.

// cbaabwbbbabbwaaq
// x = 4074, y = 9819, out = 19638, expected = 23712

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        deque<char> d;
        auto preferAB = x >= y;
        int ans = 0;
        auto checkDeck = [&]() -> int {
            if (d.empty() || d.size() == 1)
                return 0;
            int k = d.size();
            int sum1 = 0, sum2 = 0;
            while (k - 2 >= 0) {
                if (preferAB && d[k - 2] == 'a' && d[k - 1] == 'b') {
                    d.pop_back();
                    d.pop_back();
                    sum1 += x;
                    k -= 2;
                } else if (!preferAB && d[k - 2] == 'b' && d[k - 1] == 'a') {
                    d.pop_back();
                    d.pop_back();
                    sum1 += y;
                    k -= 2;
                } else
                    k -= 1;
            }
            k = d.size();
            while (k - 2 >= 0) {
                if (preferAB && d[k - 2] == 'b' && d[k - 1] == 'a') {
                    d.pop_back();
                    d.pop_back();
                    sum2 += y;
                    k -= 2;
                } else if (!preferAB && d[k - 2] == 'a' && d[k - 1] == 'b') {
                    d.pop_back();
                    d.pop_back();
                    sum2 += x;
                    k -= 2;
                } else
                    k -= 1;
            }
            return sum1 + sum2;
        };
        for (auto i = 0; i < s.size(); i++) {
            if (s[i] != 'a' && s[i] != 'b') {
                ans += checkDeck();
                d.clear();
                continue;
            }
            d.push_back(s[i]);
            ans += checkDeck();
        }
        return ans + checkDeck();
    }
};
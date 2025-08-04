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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return {};
        int minLen = INT_MAX;
        string ret;
        for (const auto& s : strs) {
            minLen = min(minLen, static_cast<int>(s.size()));
        }
        char c;
        for (auto i = 0; i < minLen; i++) {
            c = strs[0][i];
            for (auto j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) return ret;
            }
            ret += c;
        }
        return ret;
    }
};
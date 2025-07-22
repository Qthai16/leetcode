#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        if (s.empty()) return {};
        if (s.size() == 1) return {s[0]};
        string ret;
        ret.resize(s.size());
        char lastc = '\0';
        int lastCnt = 0;
        int ind = 0;
        for (auto i = 0; i < s.size(); i++) {
            const auto& c = s[i];
            if (c != lastc) {
                lastc = c;
                ret[ind++] = c;
                lastCnt = 0;
            } else if (++lastCnt < 2) {
                ret[ind++] = c;
            }
        }
        ret.resize(ind);
        return ret;
    }
};
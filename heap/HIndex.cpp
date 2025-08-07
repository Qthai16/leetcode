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
    int hIndex(vector<int> &citations) {
        priority_queue<int> h;
        for (auto &c: citations) {
            h.push(c);
        }
        int ans = 0, cur = 0;
        while (!h.empty()) {
            auto c = h.top();
            if (h.top() >= cur + 1) {// include self
                ans = max(ans, cur + 1);
                h.pop();
                cur += 1;
            } else
                break;
        }
        return ans;
    }
};
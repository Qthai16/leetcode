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
    int totalFruit(vector<int> &fruits) {
        if (fruits.empty()) return 0;
        if (fruits.size() == 1) return 1;
        unordered_map<int, int> lk;
        int l = 0, r = 0;
        int ans = 0;
        while (r < fruits.size() && l < fruits.size()) {
            lk[fruits[r]] += 1;
            if (lk.size() > 2) {
                ans = max(ans, r - l);
                while (lk.size() > 2 && l < r) {
                    auto it2 = lk.find(fruits[l]);
                    if (it2 == lk.end()) {
                        break;
                    } else {
                        it2->second = it2->second - 1;
                    }
                    if (it2->second <= 0)
                        lk.erase(it2);
                    l++;
                }
            }
            r += 1;
        }
        return max(ans, r - l);
    }
};
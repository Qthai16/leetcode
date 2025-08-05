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
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) {
            return nums[0] >= target ? 1 : 0;
        }
        int l = 0, r = 0;
        int curSum = 0, ans = INT_MAX;
        int lastr = -1;
        while (r < nums.size()) {
            if (lastr != r) {
                lastr = r;
                curSum += nums[r];
            }
            if (curSum >= target) {
                ans = min(ans, r - l + 1);
                curSum -= nums[l];
                l++;
            } else r++;
        }
        r -= 1; // backtrack r to nums.size() - 1
        while (l <= r) {
            if (curSum >= target) {
                ans = min(ans, r - l + 1);
            } else break;
            curSum -= nums[l];
            l++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
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

// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.
// return unique elements

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;
        int l = 0, r = l + 1;
        int i = 0;
        int uniqCnt = 0;
        while (l < nums.size() && r < nums.size()) {
            if (nums[l] >= nums[r]) {
                r += 1;
                continue;
            }
            if (r - l > 1) {
                for (auto j = l + 1, k = r; j < r && k < nums.size(); j++, k++) {
                    swap(nums[j], nums[k]);
                }
                l = l + 1;
                r = l + 1;
                uniqCnt += 1;
            } else {
                l += 1;
                r += 1;
                uniqCnt += 1;
            }
        }
        return uniqCnt + 1;
    }
};
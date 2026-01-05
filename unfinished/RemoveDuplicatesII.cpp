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
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;
        int l = 0, r = l + 1;
        int equalCnt = 0;
        int curMax = INT_MIN;
        while (l < nums.size() && r < nums.size()) {
            curMax = max(curMax, nums[r]);
            if (nums[r] > nums[l]) {
                if (r - l == 1) {
                    r++;
                    l++;
                } else {
                    // swap values
                    for (auto i = l + 1, k = r; i < r && k < nums.size(); i++, k++) {
                        swap(nums[i], nums[k]);
                    }
                    l = l + 1;
                    equalCnt = 0;
                }
            } else if (nums[r] < nums[l]) {
                r++;
            } else {
                if (equalCnt++ == 0) {
                    l++;
                    r++;
                } else {
                    r++;
                }
            }
        }
        return l;
    }
};
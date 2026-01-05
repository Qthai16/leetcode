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
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int cur = 1, ind = nums.size() - 2, gap = 1;
        while (ind >= 0) {
            if (nums[ind] >= cur) {
                cur += 1;
                ind--;
                // gap--;
            } else {
                // gap += 1;
                cur += 2;
                ind--;
            }
        }
        return nums[ind + 1] >= cur;
    }
};
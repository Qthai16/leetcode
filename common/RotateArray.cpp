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
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        std::vector<int> cp;
        cp.resize(nums.size());
        for (auto i = nums.size() - k; i < nums.size(); i++) {
            cp[i - (nums.size() - k)] = nums[i];
        }
        for (auto i = 0; i < nums.size() - k; i++) {
            cp[i + k] = nums[i];
        }
        swap(cp, nums);
    }
};
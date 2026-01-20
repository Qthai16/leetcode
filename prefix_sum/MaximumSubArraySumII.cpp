#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1644

int n, a, b;

class Solution {
public:
    long maximumSubArraySumII(vector<int> &nums, int a, int b) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<long> presum(nums.size() + 1, 0);
        for (auto i = 0; i < nums.size(); i++) {
            presum[i + 1] = presum[i] + nums[i];
        }
        long maxsum = LONG_MIN;
        multiset<long> ms; // keep the smallest presum[i] at begin()
        for (int i = a; i <= nums.size(); i++) {
            if (i > b)// exceed window size, erase element
                ms.erase(ms.find(presum[i - b - 1]));
            ms.insert(presum[i - a]);
            maxsum = max(maxsum, presum[i] - *ms.begin());
        }
        return maxsum;
    }
};

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;// reading in variables
    vector<int> nums(n, 0);
    for (auto i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums[i] = a;
    }
    Solution sol{};
    std::cout << sol.maximumSubArraySumII(nums, a, b) << '\n';
    return 0;
}

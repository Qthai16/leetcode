#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double oldSolution(vector<int> &nums, int k) {
        if (k >= nums.size()) k = nums.size();
        int64_t sum = 0;
        double avg = 0;
        for (auto i = 0; i < k; i++) {
            sum += nums[i];
        }
        avg = static_cast<double>(sum) / static_cast<double>(k);
        for (auto i = 1; i + k - 1 < nums.size(); i++) {
            sum += nums[i + k - 1] - nums[i - 1];
            avg = std::max(avg, static_cast<double>(sum) / static_cast<double>(k));
        }
        return avg;
    }

    double newSolution(vector<int> &nums, int k) {
        // prefix sum
        vector<int> presum(nums.size() + 1, 0);
        auto avg = [](int num, int den) -> double {
            return static_cast<double>(num)/static_cast<double>(den);
        };
        for (auto i = 0; i < nums.size(); i++) {
            presum[i + 1] = presum[i] + nums[i];
        }
        int maxsum = INT_MIN, cursum = 0;
        for (auto i = 0; i < presum.size() - k; i++) {
            cursum = presum[i + k] - presum[i];
            if (cursum > maxsum) {
                maxsum = cursum;
            }
        }
        return maxsum != INT_MIN ? avg(maxsum, k) : 0;
    }

    double findMaxAverage(vector<int> &nums, int k) {
        return newSolution(nums, k);
    }
};

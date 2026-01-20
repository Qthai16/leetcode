#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // use two pointer, left and right, inc left or decrease right based on its sum
        int l = 0, r = numbers.size() - 1;
        int sum = 0;
        const auto &a = numbers;
        while (l < r) {
            sum = a[l] + a[r];
            if (sum == target) return {l + 1, r + 1}; // return 1-index
            else if (sum < target)
                l += 1;
            else
                r -= 1;
        }
        return {l + 1, r + 1}; // return 1-index
    }
};

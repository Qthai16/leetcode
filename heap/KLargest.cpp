// #include <vector>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array/

// class Solution {
//     template<typename T>
//     using MinHeap = std::priority_queue<T, typename std::vector<T>, std::greater<T>>;
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         MinHeap<int> h;
//         for (auto i = 0; i < nums.size(); i++) {
//             h.push(nums[i]);
//             while (h.size() > k) {
//                 h.pop();
//             }
//         }
//         return h.top();
//     }
// };

class Solution {
public:
    int kthLargestSort(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - 1 - (k - 1)];
    }

    int kthLargestMinHeap(vector<int>& nums, int k) {
        using MinHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>;
        MinHeap h;
        for (auto& v : nums) {
            h.push(v);
            while (h.size() > k) {
                h.pop();
            }
        }
        return h.top();
    }

    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        return kthLargestSort(nums, k);
    }
};
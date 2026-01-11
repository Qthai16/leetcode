#include <bits/stdc++.h>
using namespace std;

// #include "../debug/StrUtils.h"

class MaxHeap : std::priority_queue<int, std::vector<int>, std::less<int>> {
public:
    using priority_queue::empty;
    using priority_queue::pop;
    using priority_queue::push;
    using priority_queue::size;
    using priority_queue::top;

    std::vector<int> get_cont() const {
        return this->c;
    }
};

class MinHeap : std::priority_queue<int, std::vector<int>, std::greater<int>> {
public:
    using priority_queue::empty;
    using priority_queue::pop;
    using priority_queue::push;
    using priority_queue::size;
    using priority_queue::top;

    std::vector<int> get_cont() const {
        return this->c;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        // using MaxHeap = priority_queue<int>;
        // using MinHeap = priority_queue<int, vector<int>, std::greater<int>>;
        MinHeap minh;
        MaxHeap maxh;
        auto i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            auto val = nums1[i] <= nums2[j] ? nums1[i] : nums2[j];
            if (maxh.empty()) {
                maxh.push(val);
            } else if (val > maxh.top()) {
                minh.push(val);
            } else {
                maxh.push(val);
            }
            if (val == nums1[i]) i++;
            else
                j++;
        }
        if (i < nums1.size()) {
            for (auto k = i; k < nums1.size(); k++) {
                auto val = nums1[k];
                if (!maxh.empty() && val > maxh.top())
                    minh.push(val);
                else
                    maxh.push(val);
            }
        }
        if (j < nums2.size()) {
            for (auto k = j; k < nums2.size(); k++) {
                auto val = nums2[k];
                if (!maxh.empty() && val > maxh.top())
                    minh.push(val);
                else
                    maxh.push(val);
            }
        }
        // balance two heaps
        while (abs(static_cast<int>(maxh.size()) - static_cast<int>(minh.size())) > 1) {
            if (maxh.size() > minh.size()) {
                auto v = maxh.top();
                maxh.pop();
                minh.push(v);
            } else {
                auto v = minh.top();
                minh.pop();
                maxh.push(v);
            }
        }
        // std::cout << libs::simple_format("maxh: {}", maxh.get_cont()) << std::endl;
        // std::cout << libs::simple_format("minh: {}", minh.get_cont()) << std::endl;
        if (maxh.size() > minh.size()) return maxh.top();
        if (maxh.size() < minh.size()) return minh.top();
        return (static_cast<double>(minh.top()) + static_cast<double>(maxh.top())) / 2;
    }
};
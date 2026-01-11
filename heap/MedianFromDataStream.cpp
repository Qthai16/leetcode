#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-median-from-data-stream/description

class MedianFinder {
    using MaxHeap = std::priority_queue<int>;
    using MinHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (maxh.empty()) {
            maxh.push(num);
        } else if (num > maxh.top()) {
            minh.push(num);
        } else {
            maxh.push(num);
        }
        balance_heap();
    }

    double findMedian() {
        if (maxh.size() == minh.size())
            return (static_cast<double>(maxh.top()) + static_cast<double>(minh.top())) / 2;
        if (maxh.size() > minh.size())
            return maxh.top();
        return minh.top();
    }

    void balance_heap() {
        if (maxh.size() == minh.size()) return;
        if (maxh.size() > minh.size()) {
            while (static_cast<int64_t>(maxh.size()) - static_cast<int64_t>(minh.size()) > 1) {
                auto v = maxh.top();
                maxh.pop();
                minh.push(v);
            }
        } else {
            while (static_cast<int64_t>(minh.size()) - static_cast<int64_t>(maxh.size()) > 1) {
                auto v = minh.top();
                minh.pop();
                maxh.push(v);
            }
        }
    }

    MaxHeap maxh;// left partition
    MinHeap minh;// right partition
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
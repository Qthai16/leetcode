#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/min-stack/description

class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        s1.push(val);
        if (smin.empty()) {
            smin.push({val, 1});
            return;
        }
        auto minval = smin.top().first;
        if (val > minval)
            return;
        if (val < minval) {
            smin.push({val, 1});
            return;
        }
        // val == minval
        smin.top().second++;
    }

    void pop() {
        auto val = s1.top();
        s1.pop();
        auto minval = smin.top().first;
        if (val == minval) {
            smin.top().second -= 1;
            if (smin.top().second <= 0) {
                smin.pop();
            }
        }
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return smin.top().first;
    }

private:
    stack<int, list<int>> s1;
    stack<pair<int, int>, list<pair<int,int>>> smin;// minval: count, contains min element
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// implement a solution with O(1) time complexity for each function.
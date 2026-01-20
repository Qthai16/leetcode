#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> oldSolution(vector<int> &nums1, vector<int> &nums2) {
        deque<int> s;// monotonic stack, decreasing order (min at top of the stack)
        unordered_map<int, int> greater;
        const auto &a = nums2;
        for (auto i = 0; i < a.size(); i++) {
            while (!s.empty() && a[i] > a[s.back()]) {
                greater[a[s.back()]] = a[i];
                s.pop_back();
            }
            s.push_back(i);
        }
        vector<int> ret;
        for (auto i = 0; i < nums1.size(); i++) {
            auto it = greater.find(nums1[i]);
            ret.push_back(it != greater.end() ? it->second : -1);
        }
        return ret;
    }

    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        // decreasing mono stack, top stack is min
        stack<int, list<int>> s;
        unordered_map<int, int> greater; // mapping next greater
        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                greater[nums2[s.top()]] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        vector<int> ret(nums1.size(), -1);
        for (int i = 0; i < ret.size(); i++) {
            auto it = greater.find(nums1[i]);
            ret[i] = it != greater.end() ? it->second : -1;
        }
        return ret;
    }
};
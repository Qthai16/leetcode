// https://leetcode.com/problems/daily-temperatures/
#include <vector>
#include <deque>
#include <stack>

using namespace std;

class Solution {
// next greater: stack giam (top stack la min)
// next smaller: stack tang (top stack la max)
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const auto &t = temperatures;
        vector<int> ret;
        ret.resize(t.size(), 0);
        stack<int> s; // next greater --> decreasing
        int i = 0;
        while (i < t.size()) {
            while(!s.empty() && t[s.top()] < t[i]) {
                ret[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
            i++;
        }
        return ret;
    }
};
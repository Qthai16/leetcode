#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    enum Operator : char {
        ADD = '+',
        SUB = '-',
        TIME = '*',
        DIVIDE = '/',
    };
    int doOperator(int first, int second, Operator op) {
        switch (op) {
            case ADD:
                return first + second;
            case SUB:
                return first - second;
            case TIME:
                return first * second;
            case DIVIDE:
                return first / second;
            default:
                break;
        }
        return INT_MIN;
    }
    int evalRPN(vector<string> &tokens) {
        stack<int, list<int>> s;
        for (const auto &val: tokens) {
            if (val.size() == 1 && (val[0] == Operator::ADD || val[0] == Operator::SUB || val[0] == Operator::TIME || val[0] == Operator::DIVIDE)) {
                if (s.size() >= 2) {
                    auto second = s.top();
                    s.pop();
                    auto first = s.top();
                    s.pop();
                    auto ret = doOperator(first, second, static_cast<Operator>(val[0]));
                    s.push(ret);
                }
            } else {
                s.push(stoi(val));
            }
        }
        return s.top();
    }
};

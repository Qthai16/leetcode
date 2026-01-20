#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/basic-calculator

class LongSolution {
public:
    enum Op : char {
        UNSET = '\0',
        ADD = '+',
        SUB = '-'
    };
    struct Operate {
        list<long> operand;
        list<Op> operators;
    };

    int doOperation(long first, long second, Op op) {
        switch (op) {
            case Op::ADD:
                // printf("%d + %d\n", first, second);
                return static_cast<int>(first + second);
            case Op::SUB:
                // printf("%d - %d\n", first, second);
                return static_cast<int>(first - second);
            default:
                return INT_MIN;
        }
        return INT_MIN;
    }

    int calculate(string s) {
        // only +, -, (, ), space and digits
        stack<Operate, list<Operate>> a;
        string tmp;
        auto handleGroup = [&](Operate &g) -> int {
            if (g.operand.size() <= g.operators.size())
                g.operand.push_front(0);
            while (g.operand.size() >= 2 && !g.operators.empty()) {
                auto op = g.operators.front();
                g.operators.pop_front();
                auto first = g.operand.front();
                g.operand.pop_front();
                auto second = g.operand.front();
                g.operand.pop_front();
                g.operand.push_front(doOperation(first, second, op));
            }
            if (g.operators.empty()) return g.operand.front();
            return doOperation(0, g.operand.front(), g.operators.front());
        };
        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!tmp.empty()) {
                    if (a.empty()) a.push(Operate{});
                    a.top().operand.push_back(stol(tmp));
                    tmp.clear();
                }
                continue;
            }
            if (s[i] == '(') {
                a.push(Operate{});
                continue;
            }
            if (s[i] == ')') {
                if (!tmp.empty()) {
                    a.top().operand.push_back(stol(tmp));
                    tmp.clear();
                }
                auto g = a.top();
                a.pop();
                if (a.empty())
                    a.push(Operate{});
                a.top().operand.push_back(handleGroup(g));
                continue;
            }
            if (s[i] == Op::ADD || s[i] == Op::SUB) {
                if (a.empty()) a.push(Operate{});
                a.top().operators.push_back(static_cast<Op>(s[i]));
                if (!tmp.empty()) {
                    a.top().operand.push_back(stol(tmp));
                    tmp.clear();
                }
                continue;
            }
            tmp += s[i];
        }
        int ret = 0;
        if (!tmp.empty()) {
            if (a.empty()) a.push(Operate{});
            a.top().operand.push_back(stol(tmp));
        }
        while (!a.empty()) {
            auto g = a.top();
            a.pop();
            auto val = handleGroup(g);
            if (a.empty()) {
                ret = val;
                break;
            }
            a.top().operand.push_back(val);
        }
        return ret;
    }
};

class Solution {
public:
    int calculate(string s) {
        long num = 0;
        int ret = 0;
        stack<int, list<int>> numstack;
        stack<int, list<int>> sign; // sign stack
        sign.push(1);
        for (int i = 0; i < s.size(); i++) {
            auto v = s[i];
            if (v >= '0' && v <= '9') {
                num = num*10l + (v - '0');
                continue;
            }
            if (v == ' ') continue;
            if (v == '+' || v == '-') {
                if (!numstack.empty()) {
                    numstack.top() += sign.top()*num;
                } else {
                    auto preret = ret;
                    ret += sign.top()*num;
                    // printf("1 change ret: %d -> %d\n", preret, ret);
                }
                num = 0;
                sign.pop();
                sign.push(v == '+' ? 1 : -1);
                continue;
            }
            if (v == '(') {
                numstack.push(0);
                sign.push(1);
                continue;
            }
            if (v == ')') {
                numstack.top() += sign.top()*num;
                auto val = numstack.top();
                num = 0;
                numstack.pop();
                sign.pop();
                if (!numstack.empty()) {
                    numstack.top() += sign.top()*val;
                } else {
                    auto preret = ret;
                    ret += sign.top()*val;
                    // printf("3 change ret: %d -> %d\n", preret, ret);
                }
            }
        }
        ret += sign.top()*num;
        return ret;
    }
};
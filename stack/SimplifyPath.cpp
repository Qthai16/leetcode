#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/simplify-path/description

class Solution {
public:
    string simplifyPath(string path) {
        if (path == "/") return path;// root dir
        stack<string, list<string>> s;
        string cur, ret;
        for (int i = 0; i < path.size(); i++) {
            auto val = path[i];
            if (val == '/') {
                if (!cur.empty() && cur != "." && cur != "..")
                    s.push(cur);
                if (cur == "..") {
                    if (s.size() > 2) {
                        s.pop();
                        s.pop();
                    }
                }
                if (s.empty() || s.top() != "/")
                    s.push("/");
                cur.clear();
                continue;
            }
            cur += val;
        }
        if (!cur.empty()) {
            if (cur == "..") {
                if (s.size() > 2) {
                    s.pop();
                    s.pop();
                }
            } else if (cur != ".") {
                s.push(cur);
            }
            cur.clear();
        }
        if (s.top() == "/" && s.size() > 1)
            s.pop();
        stack<string> srev;
        while (!s.empty()) {
            srev.push(s.top());
            s.pop();
        }
        while (!srev.empty()) {
            ret += srev.top();
            srev.pop();
        }
        return ret;
    }
};

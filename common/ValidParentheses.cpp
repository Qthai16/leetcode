#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> mystack;
        for (auto i = 0; i < s.size(); i++) {
            auto c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                mystack.push(c);
            } else if (c == ')' && !mystack.empty() && mystack.top() == '(') {
                mystack.pop();
            } else if (c == '}' && !mystack.empty() && mystack.top() == '{') {
                mystack.pop();
            } else if (c == ']' && !mystack.empty() && mystack.top() == '[') {
                mystack.pop();
            } else return false;
        }
        return mystack.empty();
    }
};
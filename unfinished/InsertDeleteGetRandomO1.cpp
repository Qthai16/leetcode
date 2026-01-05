#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

class RandomizedSet {
    unordered_set<int> tb;
    unordered_set<int>::const_iterator lastIt;
public:
    RandomizedSet() : tb(), lastIt(tb.end()) {
    }

    bool insert(int val) {
        auto it = tb.find(val);
        if (it != tb.end()) return false;
        tb.insert(val);
        if (lastIt == tb.end()) lastIt = tb.begin();
        return true;
    }

    bool remove(int val) {
        auto it = tb.find(val);
        if (it == tb.end()) return false;
        // if (lastIt == it) lastIt = std::next(lastIt);
        lastIt = tb.erase(it);
        if (lastIt == tb.end()) lastIt = tb.begin();
        return true;
    }

    int getRandom() {
        return *lastIt;
    }
};
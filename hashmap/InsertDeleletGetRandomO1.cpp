#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/insert-delete-getrandom-o1/description

class RandomizedSet {
    unordered_map<int, int> tb;
    vector<int> v;

public:
    RandomizedSet() : tb{}, v{} {}

    bool search(int val) {
        return tb.find(val) != tb.end();
    }

    bool insert(int val) {
        auto it = tb.find(val);
        if (it != tb.end())
            return false;
        v.push_back(val);
        tb[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!search(val))
            return false;
        auto it = tb.find(val);
        auto idx = it->second;
        v[idx] = v.back();
        tb.erase(it);
        v.pop_back();
        if (idx < v.size())
            tb[v[idx]] = idx;
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
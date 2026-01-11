#include <bits/stdc++.h>
using namespace std;

// #include "../debug/StrUtils.h"
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

//  Definition for a binary tree node.
template <typename T>
struct TreeNodeT {
    T val;
    TreeNodeT *left;
    TreeNodeT *right;
    TreeNodeT() : val{}, left(nullptr), right(nullptr) {}
    TreeNodeT(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNodeT(T x, TreeNodeT *left, TreeNodeT *right) : val(x), left(left), right(right) {}
};
using TreeNode = TreeNodeT<int>;

template<typename T>
vector<vector<TreeNodeT<T>*>> levelOrder(TreeNodeT<T> *root) {
    if (root == nullptr) return {};
    list<TreeNode *> q;
    q.push_back(root);
    int level = 0;
    vector<vector<TreeNodeT<T>*>> ret;
    while (!q.empty()) {
        ret.push_back({});
        auto size = q.size();
        for (auto i = 0; i < size; i++) {
            auto node = q.front();
            q.pop_front();
            ret[level].push_back(node);
            if (node->left) q.push_back(node->left);
            if (node->right) q.push_back(node->right);
        }
        level += 1;
    }
    return ret;
}

template<typename T>
TreeNodeT<T>* build_tree(const std::vector<T>& levelOrder, T nullval) {
    if (levelOrder.empty()) return nullptr;
    queue<TreeNodeT<T>*> q;
    auto root = new TreeNodeT<T>(levelOrder[0]);
    q.push(root);
    auto i = 1;
    while (i < levelOrder.size() && !q.empty()) {
        auto cur = q.front();
        q.pop();
        if (i < levelOrder.size()) {
            if (levelOrder[i] != nullval) {
                TreeNodeT<T>* left = new TreeNodeT<T>(levelOrder[i]);
                cur->left = left;
                q.push(left);
            }
            i++;
        }
        if (i < levelOrder.size()) {
            if (levelOrder[i] != nullval) {
                TreeNodeT<T>* right = new TreeNodeT<T>(levelOrder[i]);
                cur->right = right;
                q.push(right);
            }
            i++;
        }
    }
    return root;
}

template<typename T>
void clean_tree(TreeNodeT<T>* node) {
    auto nodes = levelOrder(node);
    for (auto& l : nodes) {
        for (auto& n : l) {
            delete n;
            n = nullptr;
        }
    }
}

class Solution {
public:
    int maxLevelSum(TreeNode *root) {
        int sum = 0, level = 0, maxsum = INT32_MIN, minlevel = INT32_MAX - 1;
        queue<TreeNode *> q;
        q.push(root);
        vector<int> levelsum;
        while (!q.empty()) {
            levelsum.push_back({});
            auto len = q.size();
            sum = 0;
            for (auto i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                levelsum[level] += node->val;
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum >= maxsum) {
                minlevel = sum > maxsum ? level : min(minlevel, level);
                maxsum = sum;
            }
            level++;
        }
        // std::cout << libs::simple_format("{}", levelsum) << std::endl;
        return minlevel + 1;
    }
};
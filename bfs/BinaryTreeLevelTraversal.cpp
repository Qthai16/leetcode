#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) return {};
        list<TreeNode *> q;
        q.push_back(root);
        int level = 0;
        vector<vector<int>> ret;
        while (!q.empty()) {
            ret.push_back({});
            auto size = q.size();
            for (auto i = 0; i < size; i++) {
                auto node = q.front();
                q.pop_front();
                ret[level].push_back(node->val);
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            level += 1;
        }
        return ret;
    }
};

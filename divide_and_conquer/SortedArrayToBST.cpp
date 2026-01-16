#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description

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
    TreeNode* divide(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;
        auto mid = start + (end - start)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = divide(nums, start, mid - 1);
        node->right = divide(nums, mid + 1, end);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return divide(nums, 0, nums.size() - 1);
    }
};

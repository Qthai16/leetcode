#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-list/description

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    pair<int, int> insertBefore(std::vector<ListNode*>& nodes, int at, int idx) {
        auto previdx = idx > 0 ? idx - 1 : -1;
        if (previdx >= 0)
            nodes[previdx]->next = nodes[idx]->next;
        nodes[idx]->next = nodes[at];
        return {idx, previdx};
    }

    ListNode *rotateRight(ListNode *head, int k) {
        auto cur = head;
        std::vector<ListNode*> nodes;
        while (cur != nullptr) {
            nodes.push_back(cur);
            cur = cur->next;
        }
        if (nodes.empty()) return nullptr;
        k = k%nodes.size();
        int i = 0, l = 0, r = nodes.size() - 1;
        while (i < k) {
            auto pair = insertBefore(nodes, l, r);
            l = pair.first;
            r = pair.second;
            if (pair.second == -1)
                break;
            i++;
        }
        return nodes[l];
    }
};
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-list

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class BadSolution {
public:
    using NodeCont = list<ListNode *>;
    struct ListIter {
        NodeCont::iterator it;
        int idx;
    };

    void insertBefore(NodeCont &nodes, ListIter at, ListIter n) {
        // unlink
        if (n.it != nodes.begin()) {
            auto prevNode = std::prev(n.it);
            (*prevNode)->next = (*n.it)->next;
        }
        if (at.it != nodes.begin()) {
            auto prevAt = std::prev(at.it);
            (*prevAt)->next = (*n.it);
        }
        (*n.it)->next = (*at.it);
        auto nodeval = *n.it;
        nodes.erase(n.it);
        nodes.insert(at.it, nodeval);
    }

    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) return 0;
        list<ListNode *> nodes;
        ListIter at{nodes.end(), -1};// pos to insert before
        queue<ListIter> q;
        ListNode *cur = head;
        auto i = 0;
        while (cur != nullptr) {
            auto iter = nodes.insert(nodes.end(), cur);
            if (cur->val >= x) {
                if (at.it == nodes.end()) {
                    at.it = iter;
                    at.idx = i;
                }
            } else {
                q.push({iter, i});
            }
            cur = cur->next;
            i++;
        }
        if (at.it == nodes.end())
            return (*nodes.begin());
        NodeCont::iterator preAt = (at.it == nodes.begin() ? nodes.end() : std::prev(at.it));
        while (!q.empty()) {
            auto nodeIt = q.front();
            q.pop();
            auto idx = nodeIt.idx;
            if (idx < at.idx)
                continue;
            insertBefore(nodes, at, nodeIt);
        }
        return (*nodes.begin());
    }
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *preCur = nullptr, *cur = nullptr, *at = nullptr, *preAt = nullptr;
        cur = head;
        ListNode *oldHead = head;
        while (cur) {
            if (cur->val >= x) {
                if (at == nullptr) {
                    at = cur;
                    preAt = preCur;
                }
                preCur = cur;
                cur = cur->next;
                continue;
            }
            // cur->val < x
            if (at == nullptr) {
                preCur = cur;
                cur = cur->next;
                continue;
            }
            auto curNext = cur->next;
            if (preCur)
                preCur->next = curNext;
            if (preAt)
                preAt->next = cur;
            preAt = cur;
            cur->next = at;
            cur = curNext;
            if (at == head) {
                head = preAt;
            }
        }
        return head;
    }
};
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* insertAfter(ListNode *at, ListNode *node) {
        if (at == nullptr) return nullptr;
        node->next = at->next;
        at->next = node;
        return at->next;
    }
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode *cur, *other;
        if (list1->val <= list2->val) {
            cur = list1;
            other = list2;
        } else {
            cur = list2;
            other = list1;
        }
        ListNode* root = new ListNode();
        root->next = cur;
        ListNode* prev = nullptr;
        while (cur && other) {
            if (cur->val <= other->val) {
                prev = cur;
                cur = cur->next;
            } else {
                // here cur val > other val, insert after prev
                auto onext = other->next;
                prev = insertAfter(prev, other);
                other = onext;
            }
        }
        if (other != nullptr) { // append remains elements in other
            prev->next = other;
        }
        auto ret = root->next;
        delete root;
        return ret;
    }
};
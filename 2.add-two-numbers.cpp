/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <algorithm>

int len(ListNode *head) {
    int res = 0;
    while (head != nullptr) {
        res++;
        head = head->next;
    }
    return res;
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode;
        int len1 = len(l1), len2 = len(l2);
        if (len2 > len1) {
            std::swap(l1, l2);
        }

        ListNode *head = l1;
        while (l2 != nullptr) {
            l1->val += l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }

        l1 = head;
        while (l1 != nullptr) {
            int carry = l1->val / 10;
            l1->val %= 10;
            if (carry != 0) {
                if (l1->next == nullptr) {
                    l1->next = new ListNode;
                }
                l1->next->val += carry;
            }
            l1 = l1->next;
        }

        return head;
    }
};
// @lc code=end

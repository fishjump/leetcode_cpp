/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
class Solution {
public:
    int length(ListNode *head) {
        int len = 0;
        while (head != nullptr) {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len = length(head);
        int target = len - n;
        if (target == 0) {
            return head->next;
        }

        int i = 1;
        ListNode *iter = head;
        while (i < target) {
            iter = iter->next;
            i++;
        }

        iter->next = iter->next->next;

        return head;
    }
};
// @lc code=end

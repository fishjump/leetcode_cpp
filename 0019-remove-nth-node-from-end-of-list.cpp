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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int calcListSize(ListNode *head) {
        if (head == nullptr) {
            return 0;
        }
        return calcListSize(head->next) + 1;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int size = calcListSize(head);

        ListNode *current = head;
        int end = size - n;
        if (end == 0) {
            current = current->next;
            delete head;
            return current;
        }

        for (int i = 0; i < end - 1; i++) {
            current = current->next;
        }

        ListNode *toBeDel = current->next;
        current->next =
            current->next != nullptr ? current->next->next : nullptr;
        delete toBeDel;

        return head;
    }
};
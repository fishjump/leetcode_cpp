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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    std::stack<int> result;
    while (l1 != nullptr && l2 != nullptr) {
      int val1 = l1->val;
      int val2 = l2->val;
      l1 = l1->next;
      l2 = l2->next;
      int sum = val1 + val2 + carry;
      carry = sum / 10;
      sum %= 10;
      result.push(sum);
    }

    if (l1 == nullptr) {
      l1 = l2;
    }

    while (l1 != nullptr) {
      int sum = l1->val + carry;
      l1 = l1->next;
      carry = sum / 10;
      sum %= 10;
      result.push(sum);
    }

    if (carry != 0) {
      result.push(carry);
    }

    ListNode *head = nullptr;
    while (!result.empty()) {
      int val = result.top();
      result.pop();
      head = new ListNode(val, head);
    }
    return head;
  }
};
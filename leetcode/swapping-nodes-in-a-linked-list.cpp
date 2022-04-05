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
  ListNode *swapNodes(ListNode *head, int k) {
    vector<int> record;
    ListNode *l = head;
    while (l) {
      record.push_back(l->val);
      l = l->next;
    }
    l = head;
    int len = record.size();
    for (int i = 0; i < len; i++) {
      if (i == k - 1) {
        l->val = record[len - k];
      } else if (i == len - k) {
        l->val = record[k - 1];
      }
      l = l->next;
    }
    return head;
  }
};

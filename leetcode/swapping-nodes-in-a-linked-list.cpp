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
    vector<ListNode *> record;
    ListNode *l = head;
    while (l) {
      record.push_back(l);
      l = l->next;
    }
    int len = record.size(), tmp = record[k - 1]->val;
    record[k - 1]->val = record[len - k]->val;
    record[len - k]->val = tmp;
    return head;
  }
};

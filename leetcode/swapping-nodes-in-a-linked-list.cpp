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
    ListNode *kn;
    int i = 1;
    while (l) {
      if (i == k) {
        kn = l;
      }
      l = l->next;
      i++;
    }
    i = i - k;
    l = head;
    while (--i) {
      l = l->next;
    }
    int t = l->val;
    l->val = kn->val;
    kn->val = t;
    return head;
  }
};

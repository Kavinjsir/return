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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head->next)
      return head->next;

    vector<ListNode *> r;
    ListNode *cur = head;
    while (cur) {
      r.push_back(cur);
      cur = cur->next;
    }

    if (r.size() == n)
      return head->next;

    int pos = r.size() - n;
    r[pos - 1]->next = r[pos]->next;
    return head;
  }
};

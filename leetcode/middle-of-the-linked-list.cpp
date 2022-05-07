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
  ListNode *middleNode(ListNode *head) {
    ListNode *cur = head;
    vector<ListNode *> r;
    while (cur) {
      r.push_back(cur);
      cur = cur->next;
    }
    int p = r.size();

    return r[r.size() / 2];
  }
};

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode();
        dummy->next = head;
        auto cur = dummy;
        for(int i = 0; i < left - 1; i++)
            cur = cur->next;

        auto h = cur, p = h->next, q = p->next;
        for(int i = 0; i < right - left; i++) {
            p->next = q->next;
            q->next = h->next;
            h->next = q;
            q = p->next;
        }

        return dummy->next;
    }
};
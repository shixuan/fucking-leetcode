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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *p1 = l1, *p2 = l2, *cur = dummy;

        while(p1 != nullptr && p2 != nullptr) {
            if(p1->val <= p2->val) {
                cur->next = p1;
                p1 = p1->next;
            }
            else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }

        if(p1 != nullptr)
            cur->next = p1;
        else
            cur->next = p2;

        return dummy->next;
    }
};
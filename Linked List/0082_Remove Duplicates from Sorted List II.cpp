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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(), tail = dummy;
        while(head != nullptr) {
            if(head->next == nullptr || head->val != head->next->val) {
                tail->next = head;
                tail = head;
            }
            while(head->next != nullptr && head->val == head->next->val)    head = head->next;
            head = head->next;
        }
        tail->next = nullptr;
        return dummy->next;
    }
};
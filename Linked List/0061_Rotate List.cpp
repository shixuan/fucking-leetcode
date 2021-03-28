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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;

        auto tail = head;
        int len = 1;
        for( ; tail->next != nullptr; tail = tail->next, len++) {}
        tail->next = head;

        k = len - k % len;
        for(int i = 0; i < k; i++, tail = tail->next) {}
        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *src = head, *tar;
        unordered_map<Node*, Node*> mp;

        while(src != NULL) {
            Node *newNode = new Node(src->val);
            mp[src] = newNode;
            src = src->next;
        }

        src = head;
        while(src != NULL) {
            tar = mp[src];
            tar->next = mp[src->next];
            tar->random = mp[src->random];
            src = src->next;
        }

        return mp[head];
    }
};
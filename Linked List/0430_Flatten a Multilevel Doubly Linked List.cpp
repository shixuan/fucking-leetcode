/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        vector<Node*> nodes;    //把链表当作二叉树dfs存入一个数组，再遍历数组重新链接

        dfs(head, nodes);
        Node* prev = head;
        if(head) head->child = NULL;
        for(int i = 1; i < nodes.size(); i++) {
            nodes[i]->prev = prev;
            prev->next = nodes[i];
            nodes[i]->child = NULL;
            prev = nodes[i];
        }

        return head;
    }

    void dfs(Node* node, vector<Node*>& nodes) {
        if(node == NULL)    return;
        nodes.push_back(node);
        dfs(node->child, nodes);
        dfs(node->next, nodes);
    }
};
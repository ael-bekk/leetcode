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
    Node* last(Node* head)
    {
        while (head->next)
            head = head->next;
        return (head);
    }
    
    Node* flatten(Node* head)
    {
        Node*   node;
        Node*   next;
        
        node = head;
        while (node)
        {
            if (node->child)
            {
                next = node->next;
                node->next = node->child;
                node->child->prev = node;
                node->child = NULL;
                node = node->next;
                flatten(node);
                node = last(head);
                node->next = next;
                if (next)
                    next->prev = node;
            }
            node = node->next;
        }
        return (head);
    }
};
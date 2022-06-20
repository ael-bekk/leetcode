/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* q = head;
    int i = 0,len = 0;
    
    while (q && ++len)
        q = q->next;

    while (head && i++ < len / 2)
        head = head->next;
    return (head);
}
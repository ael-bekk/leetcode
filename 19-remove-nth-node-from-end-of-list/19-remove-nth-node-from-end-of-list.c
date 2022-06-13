/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* q = head;
    int i = 0,len = 0;
    
    while (q && ++len)
        q = q->next;
    
    q = head;
    while (q && ++i < len - n)
        q = q->next;
    
    if (!(len - n))
        head = head->next;
    else if (i == len)
        q->next = NULL;
    else
        q->next = q->next->next;
    return (head);
}
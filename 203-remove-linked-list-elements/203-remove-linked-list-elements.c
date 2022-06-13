/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* q, *p;

    while (head && head->val == val)
    {
        q = head;
        head = head->next;
        free(q);
    }
    if (!head)
        return (NULL);
    q = head;
    while (q->next)
        if (q->next->val == val)
        {
            p = q->next;
            q->next = q->next->next;
            free(p);
        }
        else
            q = q->next;
    return (head);
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode* q = head, *p;
    int i = 0;

    if (k && head)
    {
        while (q && ++i)
            q = q->next;

        i -= (k % i);
        q = head;
        while (q->next && --i)
            q = q->next;

        p = q;
        while (p && p->next)
            p = p->next;

        p->next = head;
        head = q->next;
        q->next = NULL;
    }
    return (head);
}
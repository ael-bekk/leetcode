/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *q, *p = head;
    int i,j;
    
    i = 0;
    while (p)
    {
        j = 0;
        q = head;
        while(q != p)
        {
            j++;
            q = q->next;
        }
        if (i != j)
            return (q);
        p = p->next;
        i++;
    }   
    return (0);
}
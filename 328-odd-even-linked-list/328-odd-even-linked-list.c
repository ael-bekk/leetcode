/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head)
{
    struct ListNode *odd, *even, *tmp;
    struct ListNode *p;
    int ind = 1;

    if (head && head->next && head->next->next)
    {

        odd = head;
        even = head->next;
        tmp = even;
        p = head->next->next;
        while (p)
        {
            if (ind)
            {
                odd->next = p;
                odd = odd->next;
            }
            else
            {
                even->next = p;
                even = even->next;
            }
            ind = !ind;
            p = p->next;
        }
        odd->next = tmp;
        even->next = NULL;
    }
    return (head);
}
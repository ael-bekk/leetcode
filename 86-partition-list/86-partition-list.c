/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* hd = head;
    struct ListNode* tail = head;
    int i = 1;
    
    if (head)
    {
        while (tail->next)
        {
            tail = tail->next;
            i++;
        }
        while(hd->val >= x && i > 0)
        {
            tail->next = hd;
            hd = hd->next;
            tail = tail->next;
            tail->next = NULL;
            i--;
        }
        head = hd;
        while (hd->next && i > 1)
        {
            if (hd->next->val >= x)
            {
                tail->next = hd->next;
                hd->next = hd->next->next;
                tail = tail->next;
                tail->next = NULL;
            }
            else
                hd = hd->next;
            i--;
        }
    }
    return (head);
}
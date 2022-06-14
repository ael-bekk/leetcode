/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* push(struct ListNode* p, int val)
{
    struct ListNode* head = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->val = val;
    head->next = p;

    return (head);
}

void revers(struct ListNode** head)
{
    struct ListNode* cour = NULL;
    struct ListNode* nxt;

    nxt = (*head)->next;
    (*head)->next = cour;
    while (nxt)
    {
        cour = nxt;
        nxt = nxt->next;
        cour->next = (*head);
        (*head) = cour;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* l = NULL;
    int i, res = 0, sum;
    
    revers(&l1);
    revers(&l2);
    
    while (l1 || l2 || res)
    {
        sum = res;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        res = sum / 10;
        sum %= 10;
        l = push(l, sum);
    }
    return (l);
}
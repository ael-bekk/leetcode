/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void revers(struct ListNode* prev, struct ListNode* head, struct ListNode**first)
{
    if (head->next)
        revers(head, head->next, first);
    else
        *first = head;
    head->next = prev;
}


struct ListNode* reverseList(struct ListNode* head)
{
    if (head)
        revers(NULL, head, &head);
    return (head);
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head && head->next)
        if (head->val == head->next->val)
            head = deleteDuplicates(head->next);
        else
            head->next = deleteDuplicates(head->next);
    return (head);
}
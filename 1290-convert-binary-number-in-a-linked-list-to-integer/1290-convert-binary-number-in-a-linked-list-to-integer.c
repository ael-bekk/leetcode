/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head)
{
    int nb = 0;

    while (head)
    {
        nb = (nb << 1) + head->val;
        head = head->next;
    }
    return (nb);
}
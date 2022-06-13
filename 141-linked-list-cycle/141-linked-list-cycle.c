/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    while (head)
    {
        if (head->val == 1000000)
            return (1);
        head->val = 1000000;
        head = head->next;
    }   
    return (0);
}
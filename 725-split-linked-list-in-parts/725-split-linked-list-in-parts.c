/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize)
{
    int i = 0, j = 0, len = 0, part;
    struct ListNode* q = head;
    struct ListNode** res = (struct ListNode **)malloc(sizeof(struct ListNode*) * k);
    
    *returnSize = k;
    while (q)
    {
        len++;
        q = q->next;
    }
    
    q = head;
    while (q)
    {
        part = len / k + (len % k-- != 0);    
        len -= part;
        
        j = 1;
        res[i++] = q;
        while (q && j++ < part)
            q = q->next;
        
        head = q->next;
        q->next = NULL;
        q = head;
    }
    while (k--)
        res[i++] = NULL;
    
    return (res);
}
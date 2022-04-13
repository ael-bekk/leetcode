#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* NewElement(int data)
{
    struct ListNode *element;

    element = (struct ListNode *)malloc(sizeof(struct ListNode));
    element->val = data;
    element->next = NULL;
    return (element);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head;
    struct ListNode *l;

    l = NewElement(0);
    head = l;
    while (l1 && l2)
    {
        if (l1->next || l2->next || (l1->val + l2->val + l->val) / 10)
        l->next = NewElement((l1->val + l2->val + l->val) / 10);
        l->val = (l1->val + l2->val + l->val) % 10;
        l1 = l1->next;
        l2 = l2->next;
        l = l->next;
    }
    while (l2)
    {
        if (l2->next || (l2->val + l->val) / 10)
        l->next = NewElement((l2->val + l->val) / 10);
        l->val = (l2->val + l->val) % 10;
        l2 = l2->next;
        l = l->next;
    }
    while (l1)
    {
        if (l1->next || (l1->val + l->val) / 10)
        l->next = NewElement((l1->val + l->val) / 10);
        l->val = (l1->val + l->val) % 10;
        l1 = l1->next;
        l = l->next;
    }
    return (head);
}
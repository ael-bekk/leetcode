


typedef struct node
{
    int val;
    int min;
    struct node* next;
} MinStack;


MinStack* minStackCreate()
{
    MinStack* new = (MinStack*)malloc(sizeof(MinStack));
    new->next = NULL;
    return (new);
}

void minStackPush(MinStack* obj, int val)
{
    MinStack* head = minStackCreate();
    head->val= val;
    if (obj->next)
        head->min = (val < obj->next->min)? val : obj->next->min;
    else
        head->min = val;
    head->next = obj->next;
    obj->next = head;
}

void minStackPop(MinStack* obj)
{
    obj->next = obj->next->next;
}

int minStackTop(MinStack* obj)
{
    return (obj->next->val);
}

int minStackGetMin(MinStack* obj)
{
    return (obj->next->min);
}

void minStackFree(MinStack* obj)
{
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
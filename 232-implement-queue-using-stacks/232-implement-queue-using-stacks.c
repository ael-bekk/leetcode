


typedef struct MyQueue
{
    int x;
    struct MyQueue *next;
} MyQueue;

MyQueue* myQueueCreate()
{
    MyQueue* new = (MyQueue*)malloc(sizeof(MyQueue));
    new->next = NULL;
    return (new);
}

int myQueuePop(MyQueue* obj)
{
    if (!obj->next)
        return (0);
    MyQueue* tmp = obj->next;
    int var = tmp->x;
    obj->next = tmp->next;
    free(tmp);
    return (var);
}

void push2(MyQueue* obj, int x)
{
    MyQueue* new = myQueueCreate();
    new->x = x;
    new->next = obj->next;
    obj->next = new;
}

void myQueuePush(MyQueue* obj, int x)
{
    MyQueue* tmp = myQueueCreate();
    
    while (obj->next)
        push2(tmp, myQueuePop(obj));
    
    push2(obj, x);
    
    while (tmp->next)
        push2(obj, myQueuePop(tmp));
}

int myQueuePeek(MyQueue* obj)
{
    if (obj->next)
        return (obj->next->x);
    return (0);
}

bool myQueueEmpty(MyQueue* obj)
{
    return (!obj->next);
}

void myQueueFree(MyQueue* obj)
{
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
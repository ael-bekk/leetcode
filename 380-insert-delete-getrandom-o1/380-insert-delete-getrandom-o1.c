


typedef struct node{
    int arr[100001];
    int top;
} RandomizedSet;


RandomizedSet* randomizedSetCreate(){
    RandomizedSet *head = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    head->top = 0;
    return (head);
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
  int i = -1;
    
    while (++i < obj->top)
        if (obj->arr[i] == val)
            return (false);
    obj->arr[obj->top++] = val;
    return (true);
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
  
    int i = -1;
    
    while (++i < obj->top)
        if (obj->arr[i] == val)
        {
            obj->arr[i] = -1;
            while (++i < obj->top)
                obj->arr[i - 1] = obj->arr[i];
            obj->top--;
            return (true);
        }
    return (false);
}

int randomizedSetGetRandom(RandomizedSet* obj) {
  
    return (obj->arr[rand() % obj->top]);
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 
 * bool param_2 = randomizedSetRemove(obj, val);
 
 * int param_3 = randomizedSetGetRandom(obj);
 
 * randomizedSetFree(obj);
*/
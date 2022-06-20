


typedef struct comb
{
    char        *str;
    struct comb *next;
}   CombinationIterator;


void	ft_print_comb(CombinationIterator **last, char *s, char *tab, int l, int len)
{
    
    if (l == len)
    {
        (*last)->next = (CombinationIterator *)malloc(sizeof(CombinationIterator));
        *last = (*last)->next;
        (*last)->str = (char *)calloc(len + 1, 1);
        while (l--)
            ((*last)->str)[l] = tab[l];
        (*last)->next = NULL;
    }
    else if (!*s)
        return ;
    else
    {
        tab[l] = *s;
        ft_print_comb(last, s + 1, tab, l + 1, len);
        ft_print_comb(last, s + 1, tab, l, len);
    }
}


CombinationIterator* combinationIteratorCreate(char *s, int l)
{
    CombinationIterator *cmb = (CombinationIterator *)malloc(sizeof(CombinationIterator));
    cmb->next = NULL;
    CombinationIterator *p = cmb;
    char tab[l + 1];
    ft_print_comb(&p, s, tab, 0, l);
    return (cmb);
}

char * combinationIteratorNext(CombinationIterator* obj)
{
    char *p = obj->next->str;
    obj->next = obj->next->next;
    return (p);
}

bool combinationIteratorHasNext(CombinationIterator* obj)
{
    return (obj->next);
}

void combinationIteratorFree(CombinationIterator* obj)
{
    free(obj);
}

/**
 * Your CombinationIterator struct will be instantiated and called as such:
 * CombinationIterator* obj = combinationIteratorCreate(characters, combinationLength);
 * char * param_1 = combinationIteratorNext(obj);
 
 * bool param_2 = combinationIteratorHasNext(obj);
 
 * combinationIteratorFree(obj);
*/
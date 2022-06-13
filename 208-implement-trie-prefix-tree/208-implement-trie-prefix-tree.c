


typedef struct trie
{
    char *word;
    struct trie *l;
    struct trie *r;
}   Trie;

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

bool if_prefix(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s2);
}

Trie* trieCreate()
{
    Trie* new = (Trie *)malloc(sizeof(Trie));
    new->word = "ABCD";
    new->l = new->r = NULL;
    return(new);
}

void trieInsert(Trie* obj, char * word)
{
    int cmp = ft_strcmp(obj->word, word);
    if (cmp > 0 && obj->r)
        trieInsert(obj->r, word);
    else if (cmp > 0)
        {
            obj->r = trieCreate();
            obj->r->word = word;
        }
    else if (cmp < 0 && obj->l)
        trieInsert(obj->l, word);
    else if (cmp < 0)
        {
            obj->l = trieCreate();
            obj->l->word = word;
        }
}

bool trieSearch(Trie* obj, char * word)
{
    if (!obj)
        return (false);
    int cmp = ft_strcmp(obj->word, word);
    if (cmp > 0)
        return (trieSearch(obj->r, word));
    if (cmp < 0)
        return (trieSearch(obj->l, word));
    return (true);    
}

bool trieStartsWith(Trie* obj, char * prefix)
{
    if (!obj)
        return (false);
    if (!if_prefix(obj->word, prefix))
        return (true);
    return (trieStartsWith(obj->r, prefix) || trieStartsWith(obj->l, prefix));
}

void trieFree(Trie* obj)
{
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
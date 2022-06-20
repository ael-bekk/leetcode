typedef struct rotten
{
    int min;
    int x;
    int y;
    struct rotten *next;
}   rotten;

typedef struct queue
{
	rotten *front;
	rotten *back;
} queue;

void add(queue *rott,int min, int x, int y, int** grid)
{
    rotten *new = (rotten *)malloc(sizeof(rotten));
    grid[x][y] = 2;
    new->min = min;
    new->x = x;
    new->y = y;
    new->next = NULL;
    if (!rott->front)
    {
        rott->front = rott->back = new;
        return;
    }
    rott->back->next = new;
    rott->back = new;
}

int orangesRotting(int** grid, int s, int* c)
{
    int i = -1, j, res = 0;
    rotten *tmp;
    queue *rott = (queue *)malloc(sizeof(queue));
    rott->front = rott->back = NULL;
    
    while (++i < s)
    {
        j = -1;
        while (++j < *c)
            if (grid[i][j] == 2)
                add(rott, 0, i, j, grid);
    }
    
    while (rott->front)
    {
        tmp = rott->front;
        res = tmp->min;
        if (tmp->x > 0 && grid[tmp->x - 1][tmp->y] == 1)
            add(rott, tmp->min + 1, tmp->x - 1, tmp->y, grid);
        if (tmp->x + 1 < s && grid[tmp->x + 1][tmp->y] == 1)
            add(rott, tmp->min + 1, tmp->x + 1, tmp->y, grid);
        if (tmp->y > 0 && grid[tmp->x][tmp->y - 1] == 1)
            add(rott, tmp->min + 1, tmp->x, tmp->y - 1, grid);
        if (tmp->y + 1 < *c && grid[tmp->x][tmp->y + 1] == 1)
            add(rott, tmp->min + 1, tmp->x, tmp->y + 1, grid);
        rott->front = rott->front->next;
        free(tmp);
    }
    
    while (--i >= 0)
    {
        j = *c;
        while (--j >= 0)
            if (grid[i][j] == 1)
                return (-1);
    }
    return (res);
}
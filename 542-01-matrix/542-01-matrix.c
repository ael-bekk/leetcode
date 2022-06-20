

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct node
{
    int x;
    int y;
    struct node *next;
}   dist;

typedef struct queue
{
	dist *front;
	dist *back;
} queue;

void add(queue *rott, int x, int y)
{
    dist *new = (dist *)malloc(sizeof(dist));
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


void update(queue *rott, int s, int c, int **mat)
{
    dist *tmp;
    while (rott->front)
    {
        tmp = rott->front;
        if (tmp->x > 0 && mat[tmp->x - 1][tmp->y] == -1)
        {
            add(rott, tmp->x - 1, tmp->y);
            mat[tmp->x - 1][tmp->y] = mat[tmp->x][tmp->y] + 1;
        }
        if (tmp->x + 1 < s && mat[tmp->x + 1][tmp->y] == -1)
        {
            add(rott, tmp->x + 1, tmp->y);
            mat[tmp->x + 1][tmp->y] = mat[tmp->x][tmp->y] + 1;
        }
        if (tmp->y > 0 && mat[tmp->x][tmp->y - 1] == -1)
        {
            add(rott, tmp->x, tmp->y - 1);
            mat[tmp->x][tmp->y - 1] = mat[tmp->x][tmp->y] + 1;
        }
        if (tmp->y + 1 < c && mat[tmp->x][tmp->y + 1] == -1)
        {
            add(rott, tmp->x, tmp->y + 1);
            mat[tmp->x][tmp->y + 1] = mat[tmp->x][tmp->y] + 1;
        }
        rott->front = rott->front->next;
        free(tmp);
    }
}

int** updateMatrix(int** mat, int s, int* c, int* rS, int** rC)
{
    int i = -1, j = -1;
    
    *rS =  s;
    *rC = (int *)malloc(sizeof(int) * s);
    while (++j < s)
        (*rC)[j] = *c;
    
    queue *rott = (queue *)malloc(sizeof(queue));
    rott->front = rott->back = NULL;
    
    while (++i < s)
    {
        j = -1;
        while (++j < *c)
            if (!(mat[i][j] *= -1))
                add(rott, i, j);
    }
    update(rott, s, *c, mat);
    return (mat);
}
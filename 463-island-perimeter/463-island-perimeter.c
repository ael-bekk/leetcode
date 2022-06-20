

int islandPerimeter(int** grid, int s, int* c)
{
    int i = -1, j, count = 0;

    while (++i < s)
    {
        j = -1;
        while (++j < *c)
            if (grid[i][j])
            {
                count += (i - 1 < 0 || !grid[i - 1][j]);
                count += (j - 1 < 0 || !grid[i][j - 1]);
                count += (!(i + 1 - s) || !grid[i + 1][j]);
                count += (!(j + 1 - *c) || !grid[i][j + 1]);
            }
    }
        
    return (count);
}
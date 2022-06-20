#define MIN(X, Y, Z) ((X <= Y && X <= Z) ? X : ((Y <= X && Y <= Z) ? Y : Z))

int countSquares(int** matrix, int s, int* c)
{
    int i = s - 1;
    int j, sum = 0;

    while (i--)
    {
        j = *c - 1;
        while (j--)
            if (matrix[i][j])
                matrix[i][j] += MIN(matrix[i + 1][j], matrix[i][j + 1], matrix[i + 1][j+ 1]);
    }
    i = -1;
    while (++i < s)
    {
        j = -1;
        while (++j < *c)
            sum += matrix[i][j];
    }
    return (sum);
}
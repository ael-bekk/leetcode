

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int *p = (int *)malloc(sizeof(int) * 27);
    int i = -1, j, l = 0, k = 0;

    while (++i < 9)
    {
        j = -1;
        memset(p, 0, sizeof(int) * 27);
        while (++j < 9)
        {
            if (board[i][j] != '.')
                if (p[board[i][j] - '0' - 1])
                    return (0);
                else
                    p[board[i][j] - '0' - 1] = 1;
        
            if (board[j][i] != '.')
                if (p[9 + board[j][i] - '0' - 1])
                    return (0);
                else
                    p[9 + board[j][i] - '0' - 1] = 1;
            
            if (board[k + j / 3][l + j % 3] != '.')
                if (p[18 + board[k + j / 3][l + j % 3] - '0' - 1])
                    return (0);
                else
                    p[18 + board[k + j / 3][l + j % 3] - '0' - 1] = 1;
        }
        l += 3;
        if (l / 9)
        {
            l = 0;
            k += 3;
        }
    }
    return (1);
}
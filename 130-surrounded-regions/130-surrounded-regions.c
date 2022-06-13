

void search(char** board, int i, int j, int S, int C)
{
    if (i < 0 || j < 0 || i >= S || j >= C || board[i][j] != 'O')
        return;
    board[i][j] = 'A';
    search(board, i + 1, j, S, C);
    search(board, i, j + 1, S, C);
    search(board, i - 1, j, S, C);
    search(board, i, j - 1, S, C);
    
}

void solve(char** board, int S, int* C)
{
    int i = -1, j = -1;


    while (++j < *C)
    {
        if (board[0][j] == 'O')
            search(board, 0, j, S, *C);
        if (board[S - 1][j] == 'O')
            search(board, S - 1, j, S, *C);
    }
    j = -1;
    while (++j < S)
    {
        if (board[j][*C - 1] == 'O')
            search(board, j, *C - 1, S, *C);
        if (board[j][0] == 'O')
            search(board, j, 0, S, *C);
    }
    i = -1;
    while (++i < S)
    {
        j = -1;
        while (++j < *C)
            if (board[i][j] == 'A')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';  
    }
}
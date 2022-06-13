bool search(char** board, int i, int j, int s, int c, char * word)
{
    if (!(*word))
        return (true);
    if (i < 0 || j < 0 || i >= s || j >= c || board[i][j] != *word)
        return (false);
    board[i][j] -= 26;
    if (search(board, i - 1, j, s, c, word + 1) || search(board, i, j - 1, s, c, word + 1)
            || search(board, i + 1, j, s, c, word + 1) || search(board, i, j + 1, s, c, word + 1))
        return (true);
    board[i][j] += 26;
    return (false);
}

bool exist(char** board, int s, int* c, char * word)
{
    int i = -1, j;

    while (++i < s)
    {
        j = -1;
        while (++j < *c)
            if (search(board, i, j, s, *c, word))
                    return (true);
    }
    return (false);
}
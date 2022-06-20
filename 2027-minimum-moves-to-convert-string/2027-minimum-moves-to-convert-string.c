

int minimumMoves(char * s){
    int i;
    int move;
    int lent;

    lent = -1;
    while (s[++lent]);
    move = 0;
    i = 0;
    while (i < lent)
    {
        if (s[i] == 'X')
        {
            move++;
            i += 3;
        }
        else
            i++;
    }
    return (move);
}
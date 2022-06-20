

bool squareIsWhite(char * coordinates)
{
    if ((coordinates[0] % 2 && !(coordinates[1] % 2)) || (!(coordinates[0] % 2) && coordinates[1] % 2))
        return (true);
    return (false);
}
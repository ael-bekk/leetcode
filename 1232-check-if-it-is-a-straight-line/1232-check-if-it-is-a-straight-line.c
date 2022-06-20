bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize)
{
    int i = 1;
    int x = (coordinates[1][0] - coordinates[0][0]);
    int y = (coordinates[1][1] - coordinates[0][1]);
    
    while (++i < coordinatesSize)
        if (y * (coordinates[i][0] - coordinates[0][0]) != (coordinates[i][1] - coordinates[0][1]) *  x )
            return (false);
    return (true);
}
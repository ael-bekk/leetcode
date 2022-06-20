

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void fill(int** image, int Size, int ColSize, int sr, int sc, int col, int newColr)
{
    if (sr >= 0 && sr < Size && sc >= 0 && sc < ColSize && image[sr][sc] == col)
    {
        image[sr][sc] = newColr;
        fill(image, Size, ColSize, sr - 1, sc, col, newColr);
        fill(image, Size, ColSize, sr, sc - 1, col, newColr);
        fill(image, Size, ColSize, sr + 1, sc, col, newColr);
        fill(image, Size, ColSize, sr, sc + 1, col, newColr);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes)
{
    int i = -1;
    *returnSize = imageSize;
    *returnColumnSizes = (int *)malloc(imageSize*sizeof(int));
    while (++i<imageSize) (*returnColumnSizes)[i] = *imageColSize;
    if (newColor != image[sr][sc])
        fill(image, imageSize, *imageColSize, sr, sc, image[sr][sc], newColor);
    return (image);
}
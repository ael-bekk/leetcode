

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MIN(X,Y) ((X < Y) ? X : Y)


void sort(int *left, int size1, int *rigth, int size2, int *arr)
{
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2)
        arr[k++] = (left[i] <= rigth[j])? left[i++] : rigth[j++] ;
    while (i < size1)
        arr[k++] = left[i++];
    while (j < size2)
        arr[k++] = rigth[j++];
}

void merge(int *arr, int size)
{
    int *left, *rigth;
    int i = 0, j = 0, k = 0, size1, size2;
    
    if (size < 2)
      return ;
    
    size1 = size / 2;
    size2 = (size + 1) / 2;
    
    left = (int *)malloc(sizeof(int) * size1);
    rigth = (int *)malloc(sizeof(int) * size2);
    
    while (i < size1)
        left[i++] = arr[j++];
    
    while (k < size2)
        rigth[k++] = arr[j++];
    
    merge(left, size1);
    merge(rigth, size2);
    
    sort(left, size1, rigth, size2, arr);
    free(left);
    free(rigth);
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int i = 0, j = 0, k = 0;
    int *arr;
    
    *returnSize = MIN(nums1Size, nums2Size);
    arr = (int *)malloc(sizeof(int) * *returnSize);
    
    merge(nums1, nums1Size);
    merge(nums2, nums2Size);
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] > nums2[j]) j++;
        else if (nums1[i] < nums2[j]) i++;
        else
        {
            arr[k++] = nums1[i++];
            j++;
        }
    }
    *returnSize = k;
    return (arr);
}
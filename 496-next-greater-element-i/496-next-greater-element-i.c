

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int i = -1,j, find;

    while (++i < nums1Size)
    {
        j = -1;
        find = -2;
        while (++j < nums2Size)
        {
            if (find == -2 && nums1[i] == nums2[j])
                find++;
            else if (find == -1 && nums1[i] < nums2[j])
                find = nums2[j];
        }
        nums1[i] = find;
    }
    *returnSize = nums1Size;
    return (nums1);
}
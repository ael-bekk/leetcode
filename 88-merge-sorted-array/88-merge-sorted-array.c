
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int *tab, i = -1, j = 0, k = 0;
    
    tab = (int *)malloc(sizeof(int) * m);
    
    while (++i < m)
        tab[i] = nums1[i];
    
    i = 0;
    while (i < m && j < n)
        if(tab[i] < nums2[j])
            nums1[k++] = tab[i++];
        else
            nums1[k++] = nums2[j++];
    while (i < m)
        nums1[k++] = tab[i++];
    while (j < n)
        nums1[k++] = nums2[j++];
}
#include <limits.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
        return (findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size));
    int part1, M_l, M_r;
    int part2, m_l, m_r;
    int start, end, length;
 
    start = 0;
    end = nums1Size;
    while (start <= end)
    {
        part1 = (start + end) / 2;
        part2 = (nums1Size + nums2Size + 1) / 2 - part1;
        
        M_l = (part1 == 0) ? INT_MIN : nums1[part1 - 1] ;
        M_r = (part1 == nums1Size) ? INT_MAX : nums1[part1] ;
        
        m_l = (part2 == 0) ? INT_MIN : nums2[part2 - 1] ;
        m_r = (part2 == nums2Size) ? INT_MAX : nums2[part2] ;
        
        if (M_l <= m_r && m_l <= M_r)
        {
            if ((nums1Size + nums2Size) % 2)
                return (MAX(M_l, m_l));
            return ((double)(MAX(M_l, m_l) + MIN(M_r, m_r)) / 2);
        }
        else if (M_l > m_r)
            end = part1 - 1;
        else
            start = part1 + 1;
    }
    return 0;
}
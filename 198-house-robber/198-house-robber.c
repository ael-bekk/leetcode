#define MAX(X,Y) ((X > Y) ? X : Y)

int rob(int* nums, int numsSize)  
{
  int i = -1, hs1 = 0, hs2 = 0, cur;
    
  while (++i < numsSize)
  {
      cur = MAX(hs1 + nums[i], hs2);
      hs1 = hs2;
      hs2 = cur;
  }
  return hs2;
}
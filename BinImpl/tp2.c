#include <stdio.h>

unsigned cmp_count; // number of comparisons performed

int increasing(int a, int b)
{
   ++cmp_count;
   if (a < b)
     return -1;
   return a > b;
}

unsigned linear_search(const int* tab, unsigned count, int val, int (*cmp)(int a, int b))
{
  unsigned int i;
  for (i = 0; i < count; ++i)
  {
    if ( (1 == (*cmp)(tab[i], val)) || tab[i] == val)
    {
      break;
    }
  }
  return i;
}

#define my_test(val) \
  cmp_count = 0; \
  printf("linear_search(a, %u, %d, increasing) = %u\n", \
         asize, (val), linear_search(a, asize, (val), increasing)); \
  printf("\twith %u comparisons\n", cmp_count);

int main()
{
  int a[] = { 1, 2, 3, 4, 5, 6, 9, 12, 15, 20, 25, 35, 38, 40, 41 };
  unsigned asize = sizeof(a) / sizeof(*a);
  puts("a[]:");
 // print_int_array(stdout, a, asize);
  my_test(0);
  my_test(6);
  my_test(8);
  my_test(41);
  my_test(42);
  return 0;
}
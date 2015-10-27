#include <stdio.h>
#include <math.h>
#include <stdlib.h>
# define MAX_COLUMN 80

unsigned int_width(double i)
{
  if (0 == i) return 1;

  unsigned nb = (i > 0 ? 0 : 1);
  i = i > 0 ? i : -i;
  return log10(i) + 1 + nb;
}

unsigned ints_width(const int* tab, unsigned count)
{
  int maxSoFar, minSoFar, minWidth, maxWidth;
  maxSoFar = minSoFar = tab[0];
  for (unsigned int i = 0; i < count; ++i)
  {
    if (tab[i] > maxSoFar) maxSoFar = tab[i]; 
    if (tab[i] < minSoFar) minSoFar = tab[i]; 
  }

  minWidth = int_width(minSoFar);
  maxWidth = int_width(maxSoFar);
  return (minWidth > maxWidth ? minWidth : maxWidth);

}

void printWhiteSpace(FILE* out, unsigned int count)
{
  for (unsigned int i = 0; i < count ; ++i)
  {
    fprintf(out, " ");
  }
}

void printOneInt(FILE*out, const int num, const unsigned int int_width, const unsigned int max_width)
{
  printWhiteSpace(out, max_width - int_width);
  fprintf(out, "%d", num);
}

void print_int_array(FILE* out, const int* tab, unsigned count)
{
  unsigned int max_width = ints_width(tab, count);
  unsigned int leadingIndex = 0;
  unsigned int numOfIntsInTheRow;
  unsigned int indexWidth = int_width(count - 1);
  for (unsigned int i = 0; i < count;)
  {
    numOfIntsInTheRow = (MAX_COLUMN - int_width(leadingIndex) - 2) / (max_width + 1);
    printWhiteSpace(out, indexWidth - int_width(i));
    fprintf(out, "[");
    fprintf(out, "%d", i);
    fprintf(out, "]");
    for (unsigned int j = i; j < i + numOfIntsInTheRow && j < count; ++j)
    {
      fprintf(out, " ");
      printOneInt(out, tab[j], int_width(tab[j]), max_width);
    }
    fprintf(out, "\n");
    i += numOfIntsInTheRow;
  }
}

int main()
{
  int a[] = {
  1, 2, 3, 4, 5, 6, 13, -35, 129, -4, 123, -4555, 1341, 2432, 111, 0, 1230
};
int b[] = {
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6
};
puts("-- a[]");
print_int_array(stdout, a, sizeof(a)/sizeof(*a));
#if 1
puts("\n-- b[]");
print_int_array(stdout, b, sizeof(b)/sizeof(*b));
puts("\n-- b[] after b[8] = 123456");
b[8] = 123456;
print_int_array(stdout, b, sizeof(b)/sizeof(*b));
puts("\n-- a[0..9]");
print_int_array(stdout, a, 10);
puts("\n-- a[0..10]");
print_int_array(stdout, a, 11);
#endif 
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned int_width(double i)
{
unsigned nb = 0;
  if (i > 0)
  {
    nb = log10(i) + 1;
  }
  else if (i < 0)
  {
    i = i * (-1);
    nb = log10((double)i) + 2;
	}
  else
  {
    nb = 1;
  }
return nb;
}
 
//------------------------------------------------------
unsigned ints_width(const int* tab, unsigned count)
{
unsigned nb[count];
unsigned max_nb = 0;

  if(tab != NULL)
  {
    for (unsigned i = 0; i < count; ++i)
    {
      nb[i] = int_width(tab[i]);
#if 0     
	( if (tab[i] > 0)
      {
        nb[i] = log10(tab[i]) + 1;
      }
      else if (i < 0)
      {
        i = (-1) * i;
        nb[i] = log10(tab[i]) + 2;
      }
      else
      {
        nb[i] = 1;
      }
#endif
    }

  for(unsigned i = 0; i < count; ++i)
  {
    if(max_nb < nb[i])
    {
      max_nb = nb[i];
    }
  }
  return max_nb;
  }
return -1;
}

//----------------print_int_array----------------------------------------
void print_int_array(FILE* out, const int* tab, unsigned count)
{
int column = 0;
int width_max = ints_width(tab, count);

//int space = width_max - width_nb + 1;


  for (unsigned i = 0; i < int_width(count - 1); ++i)
  {
		if(width_max == 0)
		{;}
    fprintf(stdout, " ");
		column ++;
	/*
    if ((column) % (width_max + 1) == 0)
    {
      fprintf(stdout, "[%d]", tab[i]);
			
    }*/
  }

	fprintf(stdout, "%s%i%s", "[", 0, "]");
	column += 3;
}
//---------------------------------------------------------------------------

int main (void)
{
#if 0
  int a[] = {-42, -1, 0, 13, 9999, 10000, 10001};
  for (unsigned i = 0; i < sizeof(a) / sizeof(*a); ++i)
  printf("int_width(%d) == %d\n", a[i], int_width(a[i]));

  int a[] = {
  1, 2, 3, 4, 5, 6, 13, -35, 129, -4, 123, -4555, 1341, 2432, 111, 0, 1230};
	printf("%d\n", ints_width(a, sizeof(a)/sizeof(*a)));
	a[3] = 99999999;
	printf("%d\n", ints_width(a, sizeof(a)/sizeof(*a)));
#endif

int a[] = {
  1, 2, 3, 4, 5, 6, 13, -35, 129, -4, 123, -4555, 1341, 2432, 111, 0, 1230
};
int b[] = {  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6,
  1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6
};
puts("-- a[]");
print_int_array(stdout, a, sizeof(a)/sizeof(*a));
puts("\n-- b[]");
print_int_array(stdout, b, sizeof(b)/sizeof(*b));
puts("\n-- b[] after b[8] = 123456");
b[8] = 123456;
print_int_array(stdout, b, sizeof(b)/sizeof(*b));
puts("\n-- a[0..9]");
print_int_array(stdout, a, 10);
puts("\n-- a[0..10]");
print_int_array(stdout, a, 11);

  return 0;
}


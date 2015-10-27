#include <stdio.h>
#include <math.h>
#include <stdlib.h>
# define MAX_COLUMN 80

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
#if 0
void print_int_array(FILE* out, const int* tab, unsigned count)
{
int column = 0;
int width_max = ints_width(tab, count);

  for (unsigned l = 0; l < int_width(count - 1) - 1; l++)
  {
    fprintf(stdout, " ");
		column ++;
 	}
	//print [0]
	fprintf(stdout, "%s%i%s", "[", 0, "]");
	column += 3;
//-----------------problem-----------------------

   for (unsigned i = 0; i < count; ++i)
    {
			int width_nb = int_width(tab[i]);
			int space = width_max - width_nb;
			//printf("%i\n", width_nb);
 
			if (width_max + column > MAX_COLUMN)
			{
				//printf("%i\n", width_nb);
				fprintf(stdout, "\n");
				column = 0;
				for (unsigned l = 0; l < int_width(count - 1) - int_width(i); l++)
				{
					fprintf(stdout, " ");
					column ++;
				}	
				fprintf(stdout, "%s%i%s", "[", i, "]");
				column += 3;
			} 

			for(int j = 0; j < space; j++)
			{
				fprintf(stdout, " ");
			}
			fprintf(stdout, " ");
			fprintf(stdout, "%i", tab[i]);
			column += width_max + 1;
    }
	fprintf(stdout, "\n");
}
#endif
void print_int_array(FILE* out, const int* tab, unsigned count)
{
int column = 0;
int max_size = ints_width(tab, count);
printf("maxsize is %i\n", max_size);

  for (int i = 0; i < int_width(count); i++)
  {
    fprintf(stdout, " ");
    column++;
  }
  fprintf(stdout, "[0]");
  column = column + 3;

int j;
  for(int i = 0; i < count; i++)
  {
    //换行条件： 当x <= 80/最大size+1 - [x]占用格数
    for (int x = 1; x <= (80 / (max_size + 1)); x++)
    {
      if ((80 / (max_size + 1) - 1) * x == i)
      {
 column = 0;
        printf("\n");
        for(j = 0; j < int_width(count) - int_width(j); j++)
        {
            fprintf(stdout, " ");
            column++;
        }
        fprintf(stdout, "[%i]", i);
        column = column + 3;
      }

  }
      int space = max_size - int_width(tab[i]) + 1;
      for (int s = 0; s < space; s++)
      {
        fprintf(stdout, " ");
        column ++;
      }
      fprintf(stdout, "%i", tab[i]);
      column = column + max_size;
  }
printf("\n");
}

//---------------------------------------------------------------------------

void insert_sort(int* tab, unsigned count)
{
int i, j;
int temp;

	for(i = 0; i < count; ++i)
	{
			temp = *(tab + i);
			for (j = i; j > 0 && *(tab + j - 1) > temp; j--)
			{
				*(tab + j) = *(tab + j - 1);
			}
			*(tab + j) = temp;
	}
}


void insert_sort_cmp(int* tab, unsigned count, int (*cmp)(int a, int b))
{
double temp = 0;
int j, i = 0;
	for(i = 0; i < count; i++)
	{
		temp = *(tab + 1);	
		for(j = i; j > 0 && cmp(*(tab + j - 1), *(tab + j)); j--)
		{
			*(tab + j) = *(tab + j - 1);
		}
		*(tab + j) = temp;
	}
}

double increasing(double a, double b)
{
   if (a < b)
     return -1;
   return a > b;
}

double decreasing(double a, double b)
{
   if (a > b)
     return -1;
   return a < b;
}



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


#if 0
int a[] = {
  1, 2, 3, 4, 5, 6, 13, -35, 129, -4, 123, -4555, 1341, 2432, 111, 0, 1230
};

unsigned asize = sizeof(a)/sizeof(*a);
puts("before");
print_int_array(stdout, a, asize);
insert_sort(a, asize);
puts("after");
print_int_array(stdout, a, asize);
#endif

return 0;
}


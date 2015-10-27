#include <stdio.h>

unsigned int_width(int i)
{
int size_nb = 0;
	if (i <= 0)
		size_nb++;
		while (i != 0)
		{
			size_nb += 1;
			i /= 10;
		}
return size_nb;
}

unsigned ints_width(const int* tab, unsigned count)
{
int size_nb[count];
	for(int i = 0; i < count; ++i)
	{
		size_nb[i] = int_width(*(tab + i));
	}

int max_size = 0;
	for(int i =0; i < count; ++i)
	{
		if(max_size < size_nb[i])
			max_size = size_nb[i];
	}
return max_size;
}

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
int main(void) 
{
/*
int a[] = { -42, -1, 0, 13, 9999, 10000, 10001 };
for (unsigned i = 0; i < sizeof(a) / sizeof(*a); ++i)
printf("int_width(%d) == %d\n", a[i], int_width(a[i]));

int a[] = {
  1, 2, 3, 4, 5, 6, 13, -35, 129, -4, 123, -4555, 1341, 2432, 111, 0, 1230
};
printf("%d\n", ints_width(a, sizeof(a)/sizeof(*a)));
a[3] = 99999999;
printf("%d\n", ints_width(a, sizeof(a)/sizeof(*a)));
*/
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

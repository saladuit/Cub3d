#include <stdio.h>

void print_str_table(char **table)
{
	size_t i = 0;
	while (table[i])
	{
		printf("%s\n", table[i]);
		i++;
	}
}

#include "utils.h"

size_t row_len(char **map)
{
	size_t i = 0;
	size_t len = 0;
	while (map[i])
	{
		i++;
		len++;
	}
	return (len);
}

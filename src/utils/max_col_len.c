#include "libft.h"
#include "utils.h"

size_t max_col_len(char **map)
{
	size_t i = 0;
	size_t len = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}

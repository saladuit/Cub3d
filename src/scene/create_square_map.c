#include "error.h"
#include "libft.h"
#include "scene.h"
#include "utils.h"

static char **allocate_rows(char **map)
{
	size_t i = 0;
	char **rows = NULL;
	i = row_len(map);
	rows = ft_calloc(i + 1, sizeof(char *));
	if (!rows)
		system_error_and_exit("calloc in allocate_rows");
	return (rows);
}
char **create_square_map(char **map)
{
	size_t i = 0;
	size_t col_len = 0;
	char **square_map = NULL;

	col_len = max_col_len(map);
	square_map = allocate_rows(map);
	i = 0;
	while (map[i])
	{
		size_t map_len = ft_strlen(map[i]);
		square_map[i] = ft_calloc(col_len + 1, sizeof(char));
		if (!square_map[i])
			system_error_and_exit("calloc in create_square_map");
		ft_strlcpy(square_map[i], map[i], map_len + 1);
		if (map_len < col_len)
			ft_memset(square_map[i] + map_len, ' ', col_len - map_len);
		free(map[i]);
		i++;
	}
	free(map);
	return (square_map);
}

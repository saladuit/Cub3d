#include "error.h"
#include "libft.h"
#include "rectangle.h"
#include "scene.h"

static char **allocate_rows(t_rectangle_dimension dim)
{
	char **rows = NULL;
	rows = ft_calloc(dim.height + 1, sizeof(char *));
	if (!rows)
		system_error_and_exit("calloc in allocate_rows");
	return (rows);
}
t_rectangle_dimension create_rectangle_map(char ***map)
{
	size_t i = 0;
	t_rectangle_dimension dim;
	char **square_map = NULL;
	size_t map_len = 0;

	dim = get_rectangle_dimension(*map);
	square_map = allocate_rows(dim);
	i = 0;
	while ((*map)[i])
	{
		map_len = ft_strlen((*map)[i]);
		square_map[i] = ft_calloc(dim.width + 1, sizeof(char));
		if (!square_map[i])
			system_error_and_exit("calloc in create_square_map");
		ft_strlcpy(square_map[i], (*map)[i], map_len + 1);
		if (map_len < dim.width)
			ft_memset(square_map[i] + map_len, ' ', dim.width - map_len);
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = square_map;
	return (dim);
}

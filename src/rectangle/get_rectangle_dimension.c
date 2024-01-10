#include "libft.h"
#include "rectangle.h"
#include "utils.h"

t_rectangle_dimension get_rectangle_dimension(char **map)
{
	t_rectangle_dimension dimension;

	dimension.width = max_col_len(map);
	dimension.height = row_len(map);
	return (dimension);
}

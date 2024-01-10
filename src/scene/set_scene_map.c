
#include "error.h"
#include "libft.h"
#include "scene.h"

bool check_adjecent_tiles(char **map, size_t row, size_t col)
{
	size_t xd[4] = {1, 0, -1, 0};
	size_t yd[4] = {0, 1, 0, -1};
	for (size_t i = 0; i < 4; i++)
	{
		if (map[row + yd[i]][col + xd[i]] == ' ')
			return (false);
	}
	return (true);
}

bool is_map_closed(char **map, t_rectangle_dimension dim)
{
	size_t row = 0;
	size_t col = 0;

	while (map[row])
	{
		while (map[row][col])
		{
			if (map[row][col] == '0')
			{
				if (col == 0 || row == 0 || row == dim.height - 1 ||
					col == dim.width - 1)
					return (false);
				else if (check_adjecent_tiles(map, row, col) == false)
					return (false);
			}
			col++;
		}
		row++;
	}
	return (true);
}

void set_scene_map(const char *string, t_scene *scene, size_t line_start)
{
	t_rectangle_dimension dim;

	check_valid_map(string + line_start);
	scene->map = ft_split(string + line_start, "\n");
	if (!scene->map)
		system_error_and_exit("ft_split in string_to_scene");
	if (scene->map[0] == NULL)
		user_error_and_exit("No map found");
	dim = create_rectangle_map(&scene->map);
	if (is_map_closed(scene->map, dim) == false)
		user_error_and_exit("Map is not closed");
}

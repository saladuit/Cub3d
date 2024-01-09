#include "error.h"
#include "libft.h"
#include "scene.h"

#include <stddef.h>

bool is_valid_character(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' ||
		c == 'W')
		return (true);
	return (false);
}

void check_valid_map(const char *string)
{
	size_t i = 0;
	size_t len = 0;
	bool found_player = false;

	while (string[i])
	{
		if (string[i] == '\n')
		{
			if (len == 0)
				user_error_and_exit("Empty line in map");
			len = 0;
		}
		else if (is_valid_character(string[i]) == false)
		{
			if (found_player == true)
				user_error_and_exit("too many players in map");
			found_player = true;
			user_error_and_exit("Invalid character in map");
		}
		len++;
		i++;
	}
	if (found_player == false)
		user_error_and_exit("No player in map");
}
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

char **allocate_rows(char **map)
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
	printf("square map:\n");
	print_str_table(square_map);
	return (square_map);
}

void set_scene_map(const char *string, t_scene *scene, size_t line_start)
{
	check_valid_map(string + line_start);
	scene->map = ft_split(string + line_start, "\n");
	if (!scene->map)
		system_error_and_exit("ft_split in string_to_scene");
	if (scene->map[0] == NULL)
		user_error_and_exit("No map found");
	scene->map = create_square_map(scene->map);
	// if (is_closed_map(scene->map) == false)
	// 	user_error_and_exit("Map is not closed");
}

void string_to_scene(char *string, t_scene *scene)
{
	size_t line_start = 0;
	line_start = set_scene_elements(string, scene);
	set_scene_map(string, scene, line_start);
}

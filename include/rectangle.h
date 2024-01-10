#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stddef.h>

typedef struct s_rectangle_dimension
{
	size_t height;
	size_t width;
} t_rectangle_dimension;

t_rectangle_dimension get_rectangle_dimension(char **map);

#endif

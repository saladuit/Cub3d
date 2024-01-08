#ifndef RGB_H
#define RGB_H

#include <stdint.h>

typedef struct s_rgb
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} t_rgb;

void string_to_rgb(const char *str, t_rgb *rgb);

#endif
